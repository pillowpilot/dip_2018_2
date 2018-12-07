#ifndef MAE_H
#define MAE_H

#include <cmath>
#include <opencv2/opencv.hpp>
#include "commons.hpp"

namespace metric
{
  class MAE
  {
  public:
    static double calculate(const cv::Mat& inputA, const cv::Mat& inputB)
    {
      CV_Assert(inputA.data && inputB.data);
      CV_Assert(inputA.rows == inputB.rows);
      CV_Assert(inputA.cols == inputB.cols);

      cv::Mat difference(inputA.rows, inputA.cols, CV_64FC3);
      difference.forEach<cv::Vec3d>([&](cv::Vec3d& value, const int position[])->void
				 {
				   const auto& row = position[0];
				   const auto& col = position[1];
				   const auto& pA = inputA.at<cv::Vec3b>(row, col);
				   const auto& pB = inputB.at<cv::Vec3b>(row, col);
				   value[0] = std::abs((int)pA[0] - (int)pB[0]);
				   value[1] = std::abs((int)pA[1] - (int)pB[1]);
				   value[2] = std::abs((int)pA[2] - (int)pB[2]);
				 }
	);
    
      //cv::Mat difference;
      //cv::absdiff(inputA, inputB, difference);

      const auto sumsPerChannel = cv::sum(difference);
      debug(sumsPerChannel);
      const double sums = sumsPerChannel[0] + sumsPerChannel[1] + sumsPerChannel[2];
      debug(sums);
      const double normalizer = 3*inputA.rows*inputA.cols;
      debug(normalizer);
      debug(sums/normalizer);

      return sums / normalizer;
    }
  };
};

#endif /* MAE_H */
