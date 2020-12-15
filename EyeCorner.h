#ifndef EYE_CORNER_H
#define EYE_CORNER_H

#include <opencv2/imgproc/imgproc.hpp>

#define cEyeLeft true
#define cEyeRight true

void createCornerKernels();
void releaseCornerKernels();
cv2::Point2f EyeCorner(cv::Mat region, bool left, bool left2);
cv2::Point2f SubpixelEyeCorner(cv::Mat region, cv::Point maxP);

#endif