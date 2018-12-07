#ifndef NOISE_H
#define NOISE_H

#include <opencv2/opencv.hpp>

namespace noise
{
  class Noise
  {
  public:
    virtual cv::Mat apply(const cv::Mat& image) = 0;
  };

};

#endif /* NOISE_H */
