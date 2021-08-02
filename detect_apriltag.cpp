//
// Created by horizon on 2021/7/31.
//

#include "detect_apriltag.h"

#define DEBUG

static apriltag_family_t *tf = NULL;
static apriltag_detector_t *td = NULL;

bool Init(float decimate, float blur, int threads) {
    tf = tag36h11_create();
    td = apriltag_detector_create();
    apriltag_detector_add_family(td, tf);
    td->quad_decimate = decimate;
    td->quad_sigma = blur;
    td->nthreads = threads;
    td->debug = false;
    td->refine_edges = 0;
    return true;
}

int HaveAprilTags(Mat const &frame) {
    if (frame.empty())
        return 0;
    Mat gray;
    if (frame.channels() == 3)
        cvtColor(frame, gray, COLOR_BGR2GRAY);
    else
        gray = frame;

    // Make an image_u8_t header for the Mat data
    image_u8_t im = {.width = gray.cols,
            .height = gray.rows,
            .stride = gray.cols,
            .buf = gray.data
    };
    zarray_t *detections = apriltag_detector_detect(td, &im);
#ifdef DEBUG
    for (int i = 0; i < zarray_size(detections); i++) {
        apriltag_detection_t *det;
        zarray_get(detections, i, &det);
        line(frame, Point(det->p[0][0], det->p[0][1]),
             Point(det->p[1][0], det->p[1][1]),
             Scalar(0, 0xff, 0), 2);
        line(frame, Point(det->p[0][0], det->p[0][1]),
             Point(det->p[3][0], det->p[3][1]),
             Scalar(0, 0, 0xff), 2);
        line(frame, Point(det->p[1][0], det->p[1][1]),
             Point(det->p[2][0], det->p[2][1]),
             Scalar(0xff, 0, 0), 2);
        line(frame, Point(det->p[2][0], det->p[2][1]),
             Point(det->p[3][0], det->p[3][1]),
             Scalar(0xff, 0, 0), 2);

        stringstream ss;
        ss << det->id;
        String text = ss.str();
        int fontface = FONT_HERSHEY_SCRIPT_SIMPLEX;
        double fontscale = 1.0;
        int baseline;
        Size textsize = getTextSize(text, fontface, fontscale, 2,
                                    &baseline);
        putText(frame, text, Point(det->c[0] - textsize.width / 2,
                                   det->c[1] + textsize.height / 2),
                fontface, fontscale, Scalar(0xff, 0x99, 0), 2);
    }
    imshow("Tag Detections", frame);
#endif


    int res = zarray_size(detections);
    apriltag_detections_destroy(detections);
    return res;
}

void Close() {
    apriltag_detector_destroy(td);
    tag36h11_destroy(tf);
}