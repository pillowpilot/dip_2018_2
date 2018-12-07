#ifndef SPECKLE_H
#define SPECKLE_H

#include <cmath>
#include <random>
#include "../commons.hpp"
#include "noise.hpp"
#include <opencv2/opencv.hpp>

namespace noise
{
  class SpeckleNoise: public Noise
  {
  private:
    double mean, variance, range;
    std::mt19937 rng;
    std::uniform_real_distribution<double> distribution;
  
  public:
    SpeckleNoise(const double mean=1.0, const double variance = 0.1):
      mean(mean), variance(variance), range(std::sqrt(variance*12 + 1) - 1),
      distribution(mean - range/2, mean + range/2)
    {
      /*std::cout << "range " << range << std::endl;
      std::cout << "Low " << mean - range/2 << std::endl;
      std::cout << "high" << mean + range/2 << std::endl;
      std::cout << "a" << distribution.a() << std::endl;
      std::cout << "b" << distribution.b() << std::endl;*/
      rng.seed(std::random_device()());
    }
  
    cv::Mat apply(const cv::Mat& image)
    {
      using commons::pixel_t;
      cv::Mat output = image.clone();

      output.forEach<pixel_t>([&](pixel_t& pixel, const int position[]) -> void
			      {
				using std::min;
				using std::max;
				using commons::intensity_t;
			       
				double red = (double)pixel[0]/255.0;
				double green = (double)pixel[1]/255.0;
				double blue = (double)pixel[2]/255.0;

				//std::cout << distribution(rng) << std::endl;
				//std::cout << distribution(rng) << std::endl;

				red += distribution(rng) * red;
				green += distribution(rng) * green;
				blue += distribution(rng) * blue;

				red *= 255.0;
				green *= 255.0;
				blue *= 255.0;

				pixel[0] = (intensity_t) max(0.0, min(255.0, red));
				pixel[1] = (intensity_t) max(0.0, min(255.0, green));
				pixel[2] = (intensity_t) max(0.0, min(255.0, blue));
			      });
    
      return output;
    }
  };

};

#endif /* SPECKLE_H */
