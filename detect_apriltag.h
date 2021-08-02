//
// Created by horizon on 2021/7/31.
//

#ifndef APRILTAG_DETECT_APRILTAG_H
#define APRILTAG_DETECT_APRILTAG_H

#ifdef __cplusplus
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

extern "C" {
#endif

#include "apriltag.h"
#include "tag36h11.h"
#include "tag25h9.h"
#include "tag16h5.h"
#include "tagCircle21h7.h"
#include "tagCircle49h12.h"
#include "tagCustom48h12.h"
#include "tagStandard41h12.h"
#include "tagStandard52h13.h"
#include "common/getopt.h"

bool Init(float decimate, float blur, int threads);

int HaveAprilTags(Mat const &frame);

void Close();

#ifdef __cplusplus
};
#endif

#endif //APRILTAG_DETECT_APRILTAG_H
