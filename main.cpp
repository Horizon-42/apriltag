//
// Created by horizon on 2021/7/31.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include "detect_apriltag.h"

using namespace std;
using namespace cv;

int main() {
    string rtsp = "rtsp://admin:horizon@1234@192.168.3.134";
    VideoCapture vc(rtsp);
    Mat frame;
    namedWindow("frame", WINDOW_GUI_NORMAL);
    Init(2.0, 2.0, 8);
    while (vc.read(frame)) {
        int tags_num = HaveAprilTags(frame);
        cout << tags_num << "\n";
        imshow("frame", frame);
        if (waitKey(5) == 27)break;
    }
    Close();
}