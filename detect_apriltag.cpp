//
// Created by horizon on 2021/7/31.
//

#include "detect_apriltag.h"

//#define DEBUG

static apriltag_family_t *ttf = NULL;
static apriltag_detector_t *ttd = NULL;

bool Init(float decimate, float blur, int threads) {
    ttf = tag36h11_create();
    ttd = apriltag_detector_create();
    apriltag_detector_add_family(ttd, ttf);
    ttd->quad_decimate = decimate;
    ttd->quad_sigma = blur;
    ttd->nthreads = threads;
    ttd->debug = false;
    ttd->refine_edges = 0;
    return true;
}

int HaveAprilTags(Mat frame) {
    if ((*frame).empty())
        return 0;
    cv::Mat gray;
    if ((*frame).channels() == 3)
        cv::cvtColor(*frame, gray, cv::COLOR_BGR2GRAY);
    else
        gray = (*frame).clone();

    // Make an image_u8_t header for the Mat data
    image_u8_t im = {.width = gray.cols,
            .height = gray.rows,
            .stride = gray.cols,
            .buf = gray.data
    };
    zarray_t *detections = apriltag_detector_detect(ttd, &im);
    if (zarray_size(detections) == 0) {
        ttd->quad_decimate = 4.0;
        detections = apriltag_detector_detect(ttd, &im);
        if (zarray_size(detections) == 0) {
            ttd->quad_sigma = 3.0;
            detections = apriltag_detector_detect(ttd, &im);
            if (zarray_size(detections) == 0) {
                ttd->quad_sigma = 4.0;
                detections = apriltag_detector_detect(ttd, &im);
            }
        }
        ttd->quad_decimate = 2.0;
        if (zarray_size(detections) == 0) {
            detections = apriltag_detector_detect(ttd, &im);
            if (zarray_size(detections) == 0) {
                ttd->quad_sigma = 3.0;
                detections = apriltag_detector_detect(ttd, &im);
            }
            ttd->quad_sigma = 2.0;
        }
    }
#ifdef DEBUG
    for (int i = 0; i < zarray_size(detections); i++) {
        apriltag_detection_t *det;
        zarray_get(detections, i, &det);
        line(*frame, cv::Point(det->p[0][0], det->p[0][1]),
             cv::Point(det->p[1][0], det->p[1][1]),
             cv::Scalar(0, 0xff, 0), 2);
        line(*frame, cv::Point(det->p[0][0], det->p[0][1]),
             cv::Point(det->p[3][0], det->p[3][1]),
             cv::Scalar(0, 0, 0xff), 2);
        line(*frame, cv::Point(det->p[1][0], det->p[1][1]),
             cv::Point(det->p[2][0], det->p[2][1]),
             cv::Scalar(0xff, 0, 0), 2);
        line(*frame, cv::Point(det->p[2][0], det->p[2][1]),
             cv::Point(det->p[3][0], det->p[3][1]),
             cv::Scalar(0xff, 0, 0), 2);

        stringstream ss;
        ss << det->id;
        cv::String text = ss.str();
        int fontface = cv::FONT_HERSHEY_SCRIPT_SIMPLEX;
        double fontscale = 1.0;
        int baseline;
        cv::Size textsize = cv::getTextSize(text, fontface, fontscale, 2,
                                            &baseline);
        cv::putText(*frame, text, cv::Point(det->c[0] - textsize.width / 2,
                                            det->c[1] + textsize.height / 2),
                    fontface, fontscale, cv::Scalar(0xff, 0x99, 0), 2);
    }
    cv::imshow("Tag Detections", *frame);
#endif

    int res = zarray_size(detections);
    apriltag_detections_destroy(detections);
    return res;
}

void Close() {
    apriltag_detector_destroy(ttd);
    tag36h11_destroy(ttf);
}

int DetectAprilTags(Mat frame) {
    apriltag_family_t *tf = tag36h11_create();
    apriltag_detector_t *td = apriltag_detector_create();
    apriltag_detector_add_family(td, tf);
    td->quad_decimate = 2;
    td->quad_sigma = 2;
    td->nthreads = 1;
    td->debug = false;
    td->refine_edges = 0;

    if ((*frame).empty())
        return 0;
    cv::Mat gray;
    if ((*frame).channels() == 3)
        cv::cvtColor(*frame, gray, cv::COLOR_BGR2GRAY);
    else
        gray = (*frame).clone();
    std::cout << "in cpp " << (*frame).size() << "\n";
    std::cout << "gray size " << gray.size() << "\n";
    // Make an image_u8_t header for the Mat data
    image_u8_t im = {.width = gray.cols,
            .height = gray.rows,
            .stride = gray.cols,
            .buf = gray.data
    };
    std::cout << "40\n";
    zarray_t *detections = apriltag_detector_detect(td, &im);
    if (zarray_size(detections) == 0) {
        td->quad_decimate = 4.0;
        detections = apriltag_detector_detect(td, &im);
        if (zarray_size(detections) == 0) {
            td->quad_sigma = 3.0;
            detections = apriltag_detector_detect(td, &im);
            if (zarray_size(detections) == 0) {
                td->quad_sigma = 4.0;
                detections = apriltag_detector_detect(td, &im);
            }
        }
        td->quad_decimate = 2.0;
        if (zarray_size(detections) == 0) {
            detections = apriltag_detector_detect(td, &im);
            if (zarray_size(detections) == 0) {
                td->quad_sigma = 3.0;
                detections = apriltag_detector_detect(td, &im);
            }
            td->quad_sigma = 2.0;
        }
    }
    std::cout << "61\n";
#ifdef DEBUG
    std::cout << "64\n";
    for (int i = 0; i < zarray_size(detections); i++) {
        apriltag_detection_t *det;
        zarray_get(detections, i, &det);
        line(*frame, cv::Point(det->p[0][0], det->p[0][1]),
             cv::Point(det->p[1][0], det->p[1][1]),
             cv::Scalar(0, 0xff, 0), 2);
        line(*frame, cv::Point(det->p[0][0], det->p[0][1]),
             cv::Point(det->p[3][0], det->p[3][1]),
             cv::Scalar(0, 0, 0xff), 2);
        line(*frame, cv::Point(det->p[1][0], det->p[1][1]),
             cv::Point(det->p[2][0], det->p[2][1]),
             cv::Scalar(0xff, 0, 0), 2);
        line(*frame, cv::Point(det->p[2][0], det->p[2][1]),
             cv::Point(det->p[3][0], det->p[3][1]),
             cv::Scalar(0xff, 0, 0), 2);

        stringstream ss;
        ss << det->id;
        cv::String text = ss.str();
        int fontface = cv::FONT_HERSHEY_SCRIPT_SIMPLEX;
        double fontscale = 1.0;
        int baseline;
        cv::Size textsize = cv::getTextSize(text, fontface, fontscale, 2,
                                            &baseline);
        cv::putText(*frame, text, cv::Point(det->c[0] - textsize.width / 2,
                                            det->c[1] + textsize.height / 2),
                    fontface, fontscale, cv::Scalar(0xff, 0x99, 0), 2);
    }
    cv::imshow("Tag Detections", *frame);
    std::cout << "93\n";
#endif

    std::cout << "97\n";
    int res = zarray_size(detections);
    apriltag_detections_destroy(detections);
    std::cout << "195\n";
    apriltag_detector_destroy(td);
    std::cout << "197\n";
    tag36h11_destroy(tf);
    std::cout << "199\n";
    return res;
}