from xmlrpc.client import boolean
from ApriltagsDetector import AprilTagDetector
import numpy as np


class ApriltagsDetectorHelper(AprilTagDetector):

    def detect_tags(self, src: np.ndarray, cut_side: boolean = False):
        return super().detect_april_tags(src)
