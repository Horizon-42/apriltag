package go_apriltag

import (
	"gocv.io/x/gocv"
	"testing"
)

func TestTagDetector_DetectAprilTags(t *testing.T) {
	capture, err := gocv.OpenVideoCapture(0)
	if err != nil {
		t.Fatal(err)
	}
	frame := gocv.NewMat()
	td := NewTagDetector()
	for {
		if ok := capture.Read(&frame); !ok {
			res := td.DetectAprilTags(frame)
			if len(res) > 0 {
				println("got")
			} else {
				println("no")
			}
		}
	}
}

func main() {
	capture, err := gocv.OpenVideoCapture(0)
	if err != nil {
		return
	}
	frame := gocv.NewMat()
	td := NewTagDetector()
	for {
		if ok := capture.Read(&frame); !ok {
			res := td.DetectAprilTags(frame)
			if len(res) > 0 {
				println("got")
			} else {
				println("no")
			}
		}
	}
}
