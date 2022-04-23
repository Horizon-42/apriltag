//
// Created by horizon on 2022/4/23.
//

#ifndef APRILTAGTEST_APRILTAGDETECTOR_H
#define APRILTAGTEST_APRILTAGDETECTOR_H

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>
#include <pybind11/numpy.h>
#include <opencv2/opencv.hpp>
#include "apriltags/TagDetector.h"
#include "ndarray_converter.h"

namespace py = pybind11;

class AprilTagDetector {
private:
    AprilTags::TagDetector detector;

public:
    AprilTagDetector();

    ~AprilTagDetector();

    std::vector<float> DetectAprilTags(cv::Mat const &frame);
};


#endif //APRILTAGTEST_APRILTAGDETECTOR_H
