#ifndef COMMONS_H
#define COMMONS_H

#define debug(x) std::cout << #x << " = " << x << std::endl;
#include <iostream>
#include <cstddef> // size_t
#include <cstdint> // uint8_t
#include <opencv2/opencv.hpp>

namespace commons
{
  constexpr double EPS = 1e-9;
  const size_t graylevels = 256;
  using pixel_t = cv::Vec3b;
  using intensity_t = uint8_t; // Channel type

  using coords_t = std::pair<size_t, size_t>;
};

#endif /* COMMONS_H */
