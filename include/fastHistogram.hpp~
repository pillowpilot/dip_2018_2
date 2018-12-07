#ifndef FASTHISTOGRAM_H
#define FASTHISTOGRAM_H

#include <vector>
#include <memory>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include "commons.hpp"

namespace transform
{ 
  class FastHistogram
  {
  public:
    // Graylevels are fixed at compile time
    static constexpr auto graylevels = commons::graylevels;
    using value_t = uint16_t;
    using image_t = uint8_t;
    using coord_t = std::pair<size_t, size_t>;
    
    //  private:
  public:
    const size_t rows, cols;
    //std::vector<std::vector<std::vector<value_t>>> data;
    //std::unique_ptr<value_t[]> dataPtr;
    std::vector<std::vector<std::vector<value_t>>> data;
    
  public:
    FastHistogram(const cv::Mat& image):
      rows(image.rows),
      cols(image.cols),
      data(image.rows)
    {
      CV_Assert(image.channels() == 1); // Single channel image
      CV_Assert(image.type() == CV_8UC1); // char/uint8_t type

      for(auto& row: data)
	{
	  row.resize(image.cols);
	  for(auto& cell: row)
	    cell.resize(graylevels);
	}

      calculateData(image);
    }

    std::vector<value_t> getHistogram(const coord_t& a, const coord_t& b) const
    {
      std::vector<value_t> histogram(graylevels);

      const auto& dataB = data[b.first][b.second];

      if(a.first == 0 && a.second == 0) // Touches top left corner
	std::copy(std::begin(dataB), std::end(dataB), std::begin(histogram));
      
      else if(a.first == 0 && a.second != 0) // Touches top border
	for(size_t level = 0; level < graylevels; ++level)
	  histogram[level] = dataB[level] - data[b.first][a.second-1][level];
      
      else if( a.first != 0 && a.second == 0) // Touches left border
	for(size_t level = 0; level < graylevels; ++level)
	  histogram[level] = dataB[level] - data[a.first-1][b.second][level];

      else // Tipical case
	for(size_t level = 0; level < graylevels; ++level)
	  histogram[level] = // First add, then substract to avoid signed temp values
	    dataB[level] +
	    data[a.first-1][a.second-1][level] -
	    data[b.first][a.second-1][level] -
	    data[a.first-1][b.second][level];

      return histogram;
    }

  private:
    void calculateData(const cv::Mat& image)
    {
      // Fill upper left
      auto imageRow0Ptr = image.ptr<image_t>(0);
      std::fill(std::begin(data[0][0]), std::end(data[0][0]), 0);
      data[0][0][*imageRow0Ptr] = 1;
      ++imageRow0Ptr;

      // Fill upper row
      for(size_t col = 1; col < cols; ++col)
	{
	  std::fill(std::begin(data[0][col]), std::end(data[0][col]), 0);
	  data[0][col][*imageRow0Ptr] = 1;
	  ++imageRow0Ptr;
	}

      // Fill all other rows
      for(size_t row = 1; row < rows; ++row)
	{ 
	  auto imageRowPtr = image.ptr<image_t>(row);
	  std::fill(std::begin(data[row][0]), std::end(data[row][0]), 0);
	  data[row][0][*imageRowPtr] += 1;
	  ++imageRowPtr;
	  for(size_t col = 1; col < cols; ++col)
	    {
	      for(size_t level = 0; level < graylevels; ++level)
		{
		  data[row][col][level] =
		    data[row-1][col][level] +
		    data[row][col-1][level] -
		    data[row-1][col-1][level];
		}
	      data[row][col][*imageRowPtr] += 1;
	      ++imageRowPtr;
	    }
	}
    }
  };
};

#endif /* FASTHISTOGRAM_H */
