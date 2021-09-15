//
// Created by horizon on 2021/7/31.
//

#ifndef APRILTAG_DETECT_APRILTAG_H
#define APRILTAG_DETECT_APRILTAG_H

#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include "apriltags/TagDetector.h"

typedef cv::Mat *Mat;
using namespace std;
#else
typedef void *Mat;
#endif

#ifdef __cplusplus
extern "C"
{
#include "apriltags/Tag16h5.h"
#include "apriltags/Tag25h7.h"
#include "apriltags/Tag25h9.h"
#include "apriltags/Tag36h9.h"
#include "apriltags/Tag36h11.h"
#endif

    bool Init();

    int HaveAprilTags(Mat frame);

    void Close();

#ifdef __cplusplus
};
#endif

#endif //APRILTAG_DETECT_APRILTAG_H
