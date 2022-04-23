//
// Created by horizon on 2022/4/23.
//

#include "AprilTagDetector.h"

std::vector<float>
AprilTagDetector::DetectAprilTags(const cv::Mat &frame) {
    if (frame.empty())
        return {};
    cv::Mat image_gray;
    if (frame.channels() == 3)
        cv::cvtColor(frame, image_gray, cv::COLOR_BGR2GRAY);
    else
        image_gray = frame.clone();
    vector<AprilTags::TagDetection> detections = detector.extractTags(image_gray);
    image_gray.release();

    if (detections.size() > 0) {
        std::vector<float> points(detections.size() * 3);
        for (int i = 0; i < detections.size(); ++i) {
            points[i * 3] = detections[i].cxy.first;
            points[i * 3 + 1] = detections[i].cxy.second;
            points[i * 3 + 2] = detections[i].id;
        }
#ifdef DEBUG
        for (int i = 0; i < detections.size(); ++i) {
            cv::circle(frame, {int(detections[i].cxy.first), int(detections[i].cxy.second)}, 3,
                       {0, 255, 0}, -1);
            cv::putText(frame, to_string(detections[i].id),
                        {int(detections[i].p[0].first), int(detections[i].p[0].second)}, 0,
                        .5, {0, 0, 255});
        }
#endif
        return points;
    }
    return {};
}

PYBIND11_MODULE(ApriltagsDetector, m) {
    NDArrayConverter::init_numpy();

    py::class_<AprilTagDetector>(m, "AprilTagDetector")
            .def(py::init<>())
            .def("detect_april_tags", &AprilTagDetector::DetectAprilTags);
}