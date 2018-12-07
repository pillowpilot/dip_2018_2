#ifndef ENTROPY_H
#define ENTROPY_H

#include <cmath>
#include <opencv2/opencv.hpp>
#include "../commons.hpp"
#include "../fastHistogram.hpp"

namespace transform
{
  class Entropy
  {
  public:
    using coords_t = commons::coords_t;
  
  private:
    const size_t imageArea;
    const FastHistogram fh;
  
  public:
    Entropy(const cv::Mat& input):
      imageArea(input.rows*input.cols),
      fh(input)
    {
      CV_Assert(input.channels() == 1);
    }

    double calculate(const coords_t& a, const coords_t& b) const
    {
      const auto histogram = fh.getHistogram(a, b);

      double distribution[FastHistogram::graylevels];
      for(size_t i = 0; i < FastHistogram::graylevels; ++i)
	distribution[i] = (double)histogram[i] / imageArea;

      double sum = 0.0;
      for(size_t i = 0; i < FastHistogram::graylevels; ++i)
	if(std::abs(distribution[i]) > commons::EPS)
	  sum += distribution[i] * log2(distribution[i]);

      return -sum;
    }
  };

};

#endif /* ENTROPY_H */
