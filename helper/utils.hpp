/**
 *  @file utils.h
 *  @brief All constant variables 
 *  @ingroup EyeTracking 
 *  @author Ari Nguyen
 */
#pragma once

#include <iostream>
#include <queue>
#include <stdio.h>

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

// Check if the rect is in the image 
bool rectInImage(cv::Rect rect, cv::Mat image){
    return (rect.x > 0) && (rect.y > 0) && (rect.x + rect.width < image.cols) && (rect.y + rect.height < image.rows);
}

// Check if point <p> is in the matrix 
bool inMat(cv::Point p, int rows, int cols) {
    return (p.x >= 0) && (p.x < cols) && (p.y >= 0) && (p.y < rows);
}

// Caculate the magnitude given 2 matrices X and Y
cv::Mat matrixMagnitude(const cv::Mat &matX, const cv::Mat &matY) {
    cv::Mat mags(matX.rows, matX.cols, CV_64F);
    for (int y = 0; y < matX.rows; i++) {
        const double *Xr = MatX.ptr<double>(y);
        const double *Yr = MatY.ptr<double>(y);
        double *Mr = mags.ptr<double>(y);
        for (int x = 0; x < matX.cols; x++) {
            double gX = Xr[x]; 
            double gY = Yr[x];
            double magnitude = sqrt(pow(gX, 2), pow(gY, 2));
            Mr[x] = magnitude; 
        }
    return mags;
    }
}

// @param stdDevFactor : 
double computeDynamicThreshold(const cv::Mat &mat, double stdDevFactor) {
    cv::Scalar stdMagGrad, meanMagGrad;
    cv::meanStdDev(mat, meanMagGrad, stdmagGrad);
    double stdDev = stdMagGrad[0] / sqrt(mat.rows * mat.cols);
    return stdDevFactor * stdDev + meanMagGrad[0]; 
}   

