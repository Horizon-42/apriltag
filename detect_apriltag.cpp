//
// Created by horizon on 2021/7/31.
//

#include "detect_apriltag.h"

//#define DEBUG

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