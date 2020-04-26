#include <iostream>
#include <vector>

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
        //std::cin.get();
        return -1;
    }

    Mat frame, hsv, thresh;

    while(true) {
        cap.read(frame);
        if (!frame.data) {
            std::cout << "frame not found" << std::endl;
            return -1;
        }

        GaussianBlur(frame, frame, Size(11, 11), 0);

        cvtColor(frame, hsv, COLOR_BGR2HSV);

        inRange(hsv, Scalar(90, 150, 70), Scalar(150, 255, 255), thresh);

        dilate(thresh, thresh, 2);
        erode(thresh, thresh, 4);

        std::vector<std::vector<Point>> contours;
        Mat contourOutput = thresh.clone();
        findContours( contourOutput, contours, RETR_LIST, CHAIN_APPROX_NONE);

        //Draw the contours
        Mat contourImage(frame.size(), CV_8UC3, Scalar(0,0,0));
        for(size_t i = 0; i < contours.size(); i++) {
            drawContours(contourImage, contours, i, Scalar(255, 255, 255));
        }

        //namedWindow("cvWindow"); // , WINDOW_NORMAL
        imshow("cvWindow", thresh);
        imshow("cvWindow2", contourImage);

        if(waitKey(10) == 27)
            break;
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
