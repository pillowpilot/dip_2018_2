#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include "commons.hpp"
#include "fastHistogram.hpp"
#include "applier.hpp"
#include "transform/entropy.hpp"
#include "transform/lexicographical.hpp"
#include "noise/gaussian.hpp"
#include "noise/speckle.hpp"
#include "noise/saltAndPepper.hpp"
#include "metric/mae.hpp"
#include "domainDefiner/maskDomainDefiner.hpp"
#include "domainDefiner/windowsUnionDomainDefiner.hpp"

std::pair<double, double> process(const std::string& filepath, const double variance)
{
  //std::cout << filepath << std::endl;
  
  cv::Mat input = cv::imread(filepath);

  cv::Mat splitted[3];
  cv::split(input, splitted);

  noise::GaussianNoise noise(0, variance);

  //noise::SaltAndPepperNoise noise(variance);
  cv::Mat noisy = noise.apply(input);

  const uint8_t maskRadius = 2;
  //domain::MaskDomainDefiner dd(maskRadius);
  domain::WindowsUnionDomainDefiner dd(input.cols, input.rows, 3, 3, maskRadius);

  transform::Applier<transform::Entropy> app;
  cv::Mat output = app.apply(noisy, maskRadius, dd);

  transform::Applier<transform::Lexicographical> appLex;
  cv::Mat outputLex = appLex.apply(noisy, maskRadius, dd);
  //cv::Mat outputLex;
  //cv::medianBlur(input, outputLex, 3);

  const double evalEntropy = metric::MAE::calculate(input, output);
  const double evalLex = metric::MAE::calculate(input, outputLex);

  //std::cout << evalEntropy << std::endl;
  //std::cout << evalLex << std::endl;

  return {evalEntropy, evalLex};
}

int main(int argc, char *argv[])
{
  namespace fs = std::filesystem;
  
  const std::string directory("bush");
  //const std::string filepath("bush/George_W_Bush_0001.jpg");

  for(double variance = 0.005; variance <= 0.165; variance += 0.010)
    {
      std::cout << variance << std::endl;
      
      std::pair<double, double> evalsMean = {0, 0};
      int c = 0;
      for(auto& p: fs::directory_iterator(directory))
	{
	  const auto evals = process(p.path().string(), variance);
	  evalsMean.first += evals.first;
	  evalsMean.second += evals.second;
	  c++;
	}
      evalsMean.first /= c;
      evalsMean.second /= c;
    
      std::cout << evalsMean.first << std::endl;
      std::cout << evalsMean.second << std::endl;
    }
  
  return 0;
}

