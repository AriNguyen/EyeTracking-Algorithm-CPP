#include <iostream>
#include <queue>
#include <thread>
#include <math.h>
#include <stdio.h>

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio/videoio_c.h>

#include "constants.h"
// #include "EyeCenter.h"
// #include "EyeCorner.h"

// Function Headers
void findEyes(cv::Mat frame_gray, cv::Rect face);
cv::Mat findSkin(cv::Mat &frame);
void detectAndDisplay(cv::Mat frame);

// Global Variables
cv::String face_cascade_name = "../res/haarcascade_frontalface_alt.xml";
cv::String eyes_cascade_name = "../res/haarcascade_eye_tree_eyeglasses.xml";
cv::CascadeClassifier face_cascade;
cv::CascadeClassifier eyes_cascade;
std::string main_window_name = "Capture - Face Detection";
std::string face_window_name = "Capture - Face";
cv::RNG rng(12345);
cv::Mat debugImage;
cv::Mat skinCrCbHist = cv::Mat::zeros(cv::Size(256, 256), CV_8UC1);


// Function Main
int main(int argc, const char** argv) {
    int deviceId = 0; // 0 = open default camera
    cv::Mat frame;

    // Load the cascades
    if (!face_cascade.load(face_cascade_name)) {
        std::cerr << "--(!)Error loading face cascade\n";
        return -1;
    }
    if (!eyes_cascade.load(eyes_cascade_name)) {
        std::cerr << "--(!)Error loading eyes cascade\n";
        return -1;
    }

    // Initialize video capture
    cv::VideoCapture capture(0);
    double fps = capture.get(CV_CAP_PROP_FPS);
    if (!capture.isOpened()) { // check if succeeded
        std::cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    
    // loop over frames from video stream
    while (true) {
        // wait for new frame from camera and store into 'frame'
        capture.read(frame);
        if (frame.empty()) { // check if succedded
            std::cerr << "ERROR! Blank frame grabbed\n";
            break;
        }

        // Apply Cascade classifier to the frame
        detectAndDisplay(frame);

        std::cerr << "Frame per second (FPS): " << fps << std::endl;

        if (cv::waitKey(10) == 27)
            break; // escape
    }
    
    return 0;
}


//
void findEyes(cv::Mat frame_gray, cv::Rect face) {
    cv::Mat faceROI = frame_gray(face);
}

cv::Mat findSkin(cv::Mat &frame) {

}

// detect eyes and pulpil region, then display to the frame
void detectAndDisplay(cv::Mat frame) {
    std::vector<cv::Rect> faces;

    std::vector<cv::Mat> rgbChannels(3);
    cv::split(frame, rgbChannels);
    cv::Mat frame_gray = rgbChannels[2];

    // Detect faces
    face_cascade.detectMultiScale(frame_gray, faces);

    for (size_t i = 0; i < faces.size(); i++) {
        cv::rectangle(debugImage, faces[i], 1234);
    }

    // if (faces.size > 0) 
    //     findEyes(frame_gray, faces[0]);
    cv::imshow("Capture - Face detection", frame);
}
