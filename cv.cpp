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


    while(true) {
        Mat frame;
        cap.read(frame);

        namedWindow("cvWindow"); // , WINDOW_NORMAL
        imshow("cvWindow", frame);

        if(waitKey(10) == 27)
            break;
    }

    cap.release();
    destroyWindow("cvWindow");

    return 0;
}
