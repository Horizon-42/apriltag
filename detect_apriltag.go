package go_apriltag

/*
#cgo CPPFLAGS: -I /usr/local/include -I /usr/local/opencv4/include/opencv4 -I /usr/local/include/apriltags -I /usr/include/eigen3
#cgo LDFLAGS: -L /usr/local/lib -L /usr/local/opencv4/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_objdetect -lopencv_dnn -lethz_apriltag2 -lopencv_cudev -lopencv_cudafilters
#include <stdlib.h>
#include "detect_apriltag.h"
*/
import "C"
import (
	//"fmt"
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

type TagDetector struct {
	detecorPtr C.TagDetectorPtr
}

func (td *TagDetector) CountAprilTags(frame gocv.Mat) int {
	src := Mat{}
	src.MatSetP(frame)
	return int(C.CountTags(td.detecorPtr, src.Ptr()))
}

func (td *TagDetector) DetectAprilTags(frame gocv.Mat) ([]float64, []int) {
	src := Mat{}
	src.MatSetP(frame)
	points := gocv.NewMat()
	input := Mat{}
	input.MatSetP(points)
	ret := bool(C.DetectTags(td.detecorPtr, src.Ptr(), input.Ptr()))
	var res []float64
	var ids []int
	if ret {
		pointsNum := points.Rows()
		res = make([]float64, pointsNum*2)
		ids = make([]int, pointsNum)
		for i := 0; i < pointsNum; i++ {
			res[i*2] = float64(points.GetFloatAt(i, 0))
			res[i*2+1] = float64(points.GetFloatAt(i, 1))
			ids[i] = int(points.GetFloatAt(i, 2))
			//fmt.Printf("%v, %v at %v;\n", res[i*2], res[i*2+1], ids[i])
		}
	}
	return res, ids
}

func (td *TagDetector) IsEmpty() bool {
	return bool(C.IsEmpty(td.detecorPtr))
}

func NewTagDetector() *TagDetector {
	return &TagDetector{detecorPtr: C.NewTagDetector()}
}

func DestoryTagDetector(detector *TagDetector) {
	C.ReleaseTagDetector(&detector.detecorPtr)
}

func Init() bool {
	return bool(C.Init())
}

func HaveAprilTags(frame gocv.Mat) int {
	src := Mat{}
	src.MatSetP(frame)
	return int(C.HaveAprilTags(src.Ptr()))
}

func Close() {
	C.Close()
}
