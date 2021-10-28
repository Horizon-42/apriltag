//
// Created by horizon on 2021/7/31.
//

#include "detect_apriltag.h"

#define DEBUG

AprilTags::TagDetector *m_tagDetector(NULL);
AprilTags::TagCodes *m_tagCodes(NULL);

bool Init() {
    m_tagCodes = new AprilTags::TagCodes(AprilTags::tagCodes36h11);
    m_tagDetector = new AprilTags::TagDetector(*m_tagCodes);
    return true;
}

int HaveAprilTags(Mat frame) {
    if ((*frame).empty())
        return 0;
    cv::Mat image_gray;
    if ((*frame).channels() == 3)
        cv::cvtColor(*frame, image_gray, cv::COLOR_BGR2GRAY);
    else
        image_gray = (*frame).clone();

    vector<AprilTags::TagDetection> detections = m_tagDetector->extractTags(image_gray);
    image_gray.release();
    auto count = detections.size();
    vector<AprilTags::TagDetection>().swap(detections);
    return count;
}

void Close() {
    delete m_tagDetector, m_tagCodes;
}

TagDetector::TagDetector() {
    tagCodes = new AprilTags::TagCodes(AprilTags::tagCodes36h11);
    detector = new AprilTags::TagDetector(*tagCodes);
}

TagDetector::~TagDetector() {
    if (detector != NULL) {
        delete detector;
        detector = NULL;
    }
    if (tagCodes != NULL) {
        delete tagCodes;
        tagCodes = NULL;
    }
}

int TagDetector::CountTags(const cv::Mat &frame) {
    if (frame.empty())
        return 0;
    cv::Mat image_gray;
    if (frame.channels() == 3)
        cv::cvtColor(frame, image_gray, cv::COLOR_BGR2GRAY);
    else
        image_gray = frame.clone();

    vector<AprilTags::TagDetection> detections = detector->extractTags(image_gray);
    image_gray.release();
    auto count = detections.size();
    vector<AprilTags::TagDetection>().swap(detections);
    return count;
}

bool TagDetector::DetectTags(const cv::Mat &frame, cv::Mat &points) {
    if (frame.empty())
        return false;
    cv::Mat image_gray;
    if (frame.channels() == 3)
        cv::cvtColor(frame, image_gray, cv::COLOR_BGR2GRAY);
    else
        image_gray = frame.clone();
    vector<AprilTags::TagDetection> detections = detector->extractTags(image_gray);
    image_gray.release();
    bool ret = false;
    if (detections.size() > 0) {
        points = cv::Mat(detections.size(), 3, CV_32F);
        for (int i = 0; i < detections.size(); ++i) {
            points.at<float>(i, 0) = detections[i].cxy.first;
            points.at<float>(i, 1) = detections[i].cxy.second;
            points.at<float>(i, 2) = detections[i].id;
        }
#ifdef DEBUG
        for (int i = 0; i < detections.size(); ++i) {
            cv::circle(frame, {int(detections[i].cxy.first), int(detections[i].cxy.second)}, 3,
                       {0, 255, 0}, -1);
            cv::putText(frame, to_string(detections[i].id),
                        {int(detections[i].p[0].first), int(detections[i].p[0].second)}, 0,
                        .5, {0, 0, 255});
        }
        cv::namedWindow("show", cv::WINDOW_GUI_NORMAL);
#endif
        ret = true;
    }
    vector<AprilTags::TagDetection>().swap(detections);
    return ret;
}

TagDetectorPtr NewTagDetector() {
    return new TagDetector;
}

void ReleaseTagDetector(TagDetectorPtr detector) {
    if (detector != NULL) {
        delete detector;
        detector = NULL;
    }
}

int CountTags(TagDetectorPtr detector, Mat frame) {
    return detector->CountTags(*frame);
}

bool DetectTags(TagDetectorPtr detector, Mat frame, Mat points) {
    return detector->DetectTags(*frame, *points);
}