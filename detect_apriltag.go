package apriltag

/*
#include "detect_apriltag.h"
*/
import "C"
import "gocv.io/x/gocv"

func Init(decimate, blur float32, threads int) bool {
	return bool(C.Init(C.float(decimate), C.float(blur), C.int(threads)))
}

func HaveAprilTags(frame gocv.Mat) int {
	return int(C.HaveAprilTags(frame.Ptr()))
}

func Close() {
	C.Close()
}
