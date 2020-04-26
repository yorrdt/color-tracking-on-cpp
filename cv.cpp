#include <iostream>

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>

using namespace cv;


int ocvWindow() {

    std::cout << "ocvWindow in cv.cpp loaded" << std::endl;


    VideoCapture cap(0);
    if(cap.isOpened() == false) {
        std::cout << "Cannot open video capture" << std::endl;
        std::cin.get();
        return -1;
    }

    Mat frame, hsv, thresh;

     int lowH = 90;     // Set Hue
     int highH = 150;

     int lowS = 70;     // Set Saturation
     int highS = 255;

     int lowV = 70;     // Set Value
     int highV = 225;

    while(true) {
        cap.read(frame);

        cvtColor(frame, hsv, COLOR_BGR2HSV);

        inRange(hsv, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), thresh);

        GaussianBlur(thresh, thresh, Size(3, 3), 0);
        dilate(thresh, thresh, 2);
        erode(thresh, thresh, 4);

        //namedWindow("cvWindow"); // , WINDOW_NORMAL
        imshow("cvWindow-Original", frame);
        imshow("cvWindow-Threshold", thresh);

        if(waitKey(10) == 27)
            break;
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
