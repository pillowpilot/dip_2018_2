#ifndef SALTANDPEPPER_H
#define SALTANDPEPPER_H

#include <random>
#include "../commons.hpp"
#include "noise.hpp"
#include <opencv2/opencv.hpp>

namespace noise
{

  class SaltAndPepperNoise: public Noise
  {
  private:
    std::mt19937 rng;
    std::discrete_distribution<int> distribution;
  
  public:
    SaltAndPepperNoise(const double p)
    {
      rng.seed(std::random_device()());
      distribution = {p/2, p/2, 1 - p};
    }
  
    cv::Mat apply(const cv::Mat& image)
    {
      using commons::pixel_t;
      cv::Mat output = image.clone();

      output.forEach<pixel_t>([&](pixel_t& pixel, const int position[]) -> void
			      {
				using std::min;
				using std::max;

				const auto outcome = distribution(rng);
				if(outcome == 0)
				  pixel = {0, 0, 0};
				else if(outcome == 1)
				  pixel = {255, 255, 255};
			       
			      });
    
      return output;
    }
  };

};


#endif /* SALTANDPEPPER_H */
