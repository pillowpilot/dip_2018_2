#ifndef APPLIER_H
#define APPLIER_H

#include <queue>
#include <opencv2/opencv.hpp>
#include "commons.hpp"
#include "weightedTransform.hpp"

namespace transform
{

  class ExtendedPixel
  {
  public:
    using intensity_t = commons::intensity_t;
  private:
    double extended;
    intensity_t red, green, blue;

  public:
    ExtendedPixel(double extended, intensity_t red, intensity_t green, intensity_t blue):
      extended(extended), red(red), green(green), blue(blue)
    { }
    ExtendedPixel(const commons::pixel_t& rgbPixel):
      extended(0.0), red(rgbPixel[0]), green(rgbPixel[1]), blue(rgbPixel[2])
    { }

    bool operator<(const ExtendedPixel& other) const
    { 
      if(extended < other.extended) return true;
      else if(std::abs(extended - other.extended) < commons::EPS)
	{
	  if(red < other.red) return true;
	  else if(red == other.red)
	    {
	      if(green < other.green) return true;
	      else if(green == other.green)
		{
		  if(blue < other.blue) return true;
		  else if(blue == other.blue) return false;
		  else return false;
		}
	    }
	}

      return false;
    }

    intensity_t getRed() const { return red; }
    intensity_t getGreen() const { return green; }
    intensity_t getBlue() const { return blue; }
  };

  class Applier
  {
  public:
    static cv::Mat apply(const cv::Mat& input, const uint8_t maskRadius)
    {
      cv::Mat padded;
      cv::copyMakeBorder(input, padded,
			 maskRadius, maskRadius, maskRadius, maskRadius,
			 cv::BORDER_REFLECT101);

      cv::Mat channels[3];
      cv::split(padded, channels);

      WeightedTransform wt(channels[0], channels[1], channels[2]);
    
      cv::Mat output(padded.rows, padded.cols, padded.type());

      // Run processARow in parallel
      {
#pragma omp parallel for
	for(size_t row = maskRadius; row < padded.rows-maskRadius; ++row)
	  processARow(padded, output, wt, maskRadius, row);
      }

      return output;
    }

    static void processARow(const cv::Mat& padded, cv::Mat& output,
			    WeightedTransform transform, const uint8_t maskRadius,
			    const size_t row)
    {
      CV_Assert(padded.channels() == 3);
      CV_Assert(output.channels() == 3);

      using commons::pixel_t;
      using commons::intensity_t;

      auto outputPtr = output.ptr<pixel_t>(row);

      // Keep an array of pointers to every row of interest
      pixel_t const * rowPtr[2*maskRadius+1];
      for(int i = -(int)maskRadius; i <= maskRadius; ++i)
	rowPtr[i+maskRadius] = padded.ptr<pixel_t>(row+i);

      // Add all, except last column, of pixels in mask into a deque (double ended queue)
      std::deque<ExtendedPixel> q;
      for(int i = -(int)maskRadius; i <= maskRadius-1; ++i)
	{
	  for(size_t j = 0; j < 2*(int)maskRadius+1; ++j)
	    {
	      const pixel_t& px = *rowPtr[j];
	      //q.push_back(ExtendedPixel(0.0, px[0], px[1], px[2]));
	      q.push_back(px);
	      ++rowPtr[j];
	    }
	}
      CV_Assert(q.size() == (2*maskRadius+1)*(2*maskRadius));


      // Process pixels
      std::vector<ExtendedPixel> neighborhood;
      neighborhood.reserve((2*maskRadius+1)*(2*maskRadius+1));
      for(size_t col = maskRadius; col < padded.cols-maskRadius; ++col)
	{
	  neighborhood.clear();
	  for(const auto& ep: q)
	    neighborhood.push_back(ep);

	  for(auto& ep: neighborhood)
	    transform.calculate({row-maskRadius, col-maskRadius},
				{row+maskRadius, col+maskRadius},
				{ep.getRed(), ep.getGreen(), ep.getBlue()}); // TODO Faster
	  
	  std::sort(std::begin(neighborhood), std::end(neighborhood));
	  const auto& median = neighborhood[neighborhood.size()/2];

	  *outputPtr = {median.getRed(), median.getGreen(), median.getBlue()};
	  ++outputPtr;

	  // Update deque
	  for(size_t i = 0; i < 2*maskRadius+1; ++i)
	    {
	      q.pop_front();
	      q.push_back(*rowPtr[i]);
	      ++rowPtr[i];
	    }
	}
    }
  };
};
#endif /* APPLIER_H */
