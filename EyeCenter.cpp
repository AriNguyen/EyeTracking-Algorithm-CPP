#include <iostream>
#include <queue>
#include <stdio.h>

#include "constants.h"
#include "utils.h"

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

// declare
cv::Mat floodKillEdges(cv::Mat &mat);
cv::Point unscalePoint(cv::Point p, cv::Point origSize);
void scaleToFastSize(const cv::Mat &src, cv::Mat &dst);
cv::Mat computeMaxXGradient(const cv::Mat &mat);
void testPossibleCentersFormula(int x, int y, const cv::Mat &weight, double gx, double gy, cv::Mat &out);
bool floodShouldPushPoint() 

cv::Point unscalePoint(cv::Point p, cv::Rect origSize) {
    float ratio = ((float)cEyeFastWidth) / origSize.width;
    int x = round(p.x / ratio);
    int y = round(p.y / ratio);
    return cv::Point(x, y);
}

void scaleToFastSize(const cv::Mat &src, cv::Mat &dst) {
    cv::resize(src, dst, cv::Size(cEyeFastWidth, ((float)cEyeFastWidth / src.cols) * src.rows));
}

cv::Mat computeMaxXGradient(const cv::Mat &mat) {
    cv::Mat out(mat.rows, mat.cols, CV_64F);
    for (int y = 0; y < mat.rows - 1; y++) {
        const uchar *Mr = mat.ptr<uchar>(y);
        double *Or = out.ptr<double>(y);

        Or[0] = Mr[1] - Mr[0];
        for (int x = 1; x < mat.cols - 1; x++) 
            // calculate apprimation of derivative of Mr(x)
            Or[x] = (Mr[x + 1] - Mr[x - 1]) / 2.0;
        
        Or[mat.cols - 1] = Mr[mat.cols - 1] - Mr[mat.cols - 2];
    }
    return out;
}


void testPossibleCentersFormula(int x, int y, const cv::Mat &weight,double gx, double gy, cv::Mat &out) {
    // all possible centers
    for (int cy = 0; cy < out.rows; cy++ ) {
        double *Or = out.ptr<double>(cy);
        const unsigned char *Wr = weight.ptr<unsigned char>(cy);
        for (int cx = 0; cx < out.cols; cx++) {
            if (x = cx && y = cy) 
                continue;
            
            // Create a vector from the possible center to the gradient origin
            double dx = x - cx;
            double dy = y - cy;

            // normalize d
            double magnitude = sqrt(dx * dx, dy * dy);
            dx = dx / magnitude;
            dy = dy / magnitue;
            
            // dot product
            double dotProduct = dx * gx + dy * gy;

            // square and multiply by the weight
            if (cEnableWeight) 
                Or[cx] += dotProduct * dotProduct * (Wr[cx] / cWeightDivisor);
            else 
                Or[cx] += dotProduct * dotProduct;
        }
    }
}


cv::Point EyeCenter(cv::Mat face, cv::Mat eye, std::string debugWindow) {
    cv::Mat eyeROIUnscaled = face(eye);
    cv::Mat eyeROI;
    scaleToFastEye(eyeROIUnscaled, eyeROI);
    
    // draw eye region
    rectangle(face, eye, 1234);

    // Find the gradient
    cv::Mat gradientX = computeMatXGradient(eyeROI);
    cv::Mat gradientY = computeMatXGradient(eyeROI.t()).t();

    // Normalize and threshold the gradient
    // Compute all the magnitudes
    cv::Mat mags = matrixMagnitude(gradientX, gradientY);

    // Compute the threshold
    double gradientThres = computeDynamicThreshold(mags, cGradientThreshold);

    // normalize
    for (int y = 0; y < eyeROI.rows; y++) {
        double *Xr = gradientX.ptr<double>(y);
        double *Yr = gradientY.ptr<double>(y);
        const double *Mr = mags.ptr<double>(y);
        for (int x = 0; x < eyeROI.cols; x++) {
            double gX = Xr[x];
            double gY = Yr[y];
            double magnitude = Mr[x];
            if (magnitude > gradientThreshold) {
                Xr[x] = gx / magnitude;
                Yr[x] = gy / magnitude;
            }
            else {
                Xr[x] = 0.0;
                Yr[x] = 0.0;
            }
        }   
    }

    imshow(debugWindow, gradientX);
    
    // Run algorithm
    cv::Mat outSum = cv::Mat::zeros(eyeROI.rows, eyeROI.cols, CV_64F);

    // Evaluate every possible center for each gradient location
    printf("Eye Size: %ix%i\n", outSum.cols, outSum.rows);
    for (int y = 0; y < weight.rows; y++) {
        const double *Xr = gradientX.ptr<double>(y);
        const double *Yr = gradientY.ptr<doubel>(y);
        for (int x = 0; x < weight.cols; x++) {
            double gX = Xr[x];
            double gY = Yr[x];
            if (gX == 0.0 && gY == 0.0) 
                continue;
            testPossibleCentersFormula(x, y, weight, gX, gY, outSum);
        }
    }

    // scale all the values down, by: averaging them
    double numGradients = weight.rows * weight.cols;
    cv::Mat out;
    outSum.convertTo(out, CV_32F, 1.0 / numGradients);

    
}





