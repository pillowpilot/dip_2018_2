#ifndef WEIGHTEDTRANSFORM_H
#define WEIGHTEDTRANSFORM_H

#include <opencv2/opencv.hpp>
#include "commons.hpp"
#include "transform/entropy.hpp"

namespace transform
{
  template <typename T>
  class WeightedTransform
  {
  public:
    using coords_t = commons::coords_t;
  
  private:
    const T redTransform, greenTransform, blueTransform;
  
  public:
    WeightedTransform(const cv::Mat& redChannel,
		      const cv::Mat& greenChannel,
		      const cv::Mat& blueChannel):
      redTransform(redChannel), greenTransform(greenChannel), blueTransform(blueChannel)
    { }

    double calculate(const coords_t& a, const coords_t& b, const commons::pixel_t& rgb) const
    {
      double w1 = redTransform.calculate(a, b);
      double w2 = greenTransform.calculate(a, b);
      double w3 = blueTransform.calculate(a, b);
      w1 /= w1 + w2 + w3;
      w2 /= w1 + w2 + w3;
      w3 /= w1 + w2 + w3;

      return w1*rgb[0] + w2*rgb[1] + w3*rgb[2];
      //return w1*rgb[0] + w2*rgb[0] + w3*rgb[0];
    }
  };
};

#endif /* WEIGHTEDTRANSFORM_H */
