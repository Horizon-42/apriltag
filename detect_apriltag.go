package go_apriltag

/*
#cgo CPPFLAGS: -I /usr/local/include -I /usr/local/opencv4/include/opencv4 -I /usr/local/include/apriltag -I /usr/local/include/apriltag/common
#cgo LDFLAGS: -L /usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_objdetect -lopencv_dnn -lapriltag
#include <stdlib.h>
#include "detect_apriltag.h"
*/
import "C"
import (
	"fmt"
	"gocv.io/x/gocv"
)

type Mat struct {
	p C.Mat
}

func (m *Mat) MatSetP(mat gocv.Mat) {
	m.p = C.Mat(mat.Ptr())
}

func (m *Mat) Ptr() C.Mat {
	return m.p
}

func Init(decimate, blur float32, threads int) bool {
	return bool(C.Init(C.float(decimate), C.float(blur), C.int(threads)))
}

func HaveAprilTags(frame gocv.Mat) int {
	src := Mat{}
	src.MatSetP(frame)
	return int(C.HaveAprilTags(src.Ptr()))
}

func DetectAprilTags(frame gocv.Mat) int {
	src := Mat{}
	src.MatSetP(frame)
	fmt.Println(frame.Size())
	return int(C.DetectAprilTags(src.Ptr()))
}

func Close() {
	C.Close()
}
