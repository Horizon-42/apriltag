import cv2
from detect_apriltags import ApriltagsDetectorHelper
import os


def test_detect_tags(data_dir: str):
    adh = ApriltagsDetectorHelper()
    frame_paths = [os.path.join(data_dir, p) for p in os.listdir(data_dir)]
    for fp in frame_paths:
        frame = cv2.imread(fp)
        res = adh.detect_tags(frame)
        print(res)


if __name__ == "__main__":
    test_detect_tags(
        data_dir="/home/horizon/go-work/src/world_coord_server/CalData/20ba0e4e_54e959ce_87a71223_a21335be/cam0")
