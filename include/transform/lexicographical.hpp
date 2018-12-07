#ifndef LEXICOGRAPHICAL_H
#define LEXICOGRAPHICAL_H

#include <cmath>
#include <opencv2/opencv.hpp>
#include "../commons.hpp"
#include "../fastHistogram.hpp"

namespace transform
{
  class Lexicographical
  {
  public:
    using coords_t = commons::coords_t;
  
  private:
  
  public:
    Lexicographical(const cv::Mat& input)
    {
      CV_Assert(input.channels() == 1);
    }

    double calculate(const coords_t& a, const coords_t& b) const
    {
      return 0.0;
    }
  };

};

#endif /* LEXICOGRAPHICAL_H */
