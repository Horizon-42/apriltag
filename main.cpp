#include "detect_apriltag.h"

int main()
{
    auto m_cap = cv::VideoCapture(0);
    Init();
    if (!m_cap.isOpened())
    {
        cerr << "ERROR: Can't find video device " << 0 << "\n";
        exit(1);
    }
    cv::Mat image;
    cv::namedWindow("frame", cv::WINDOW_GUI_NORMAL);
    while (42)
    {
        m_cap >> image;
        auto res = HaveAprilTags(&image);
        std::cout << res << "\n";
        cv::imshow("frame", image);
        if (char(cv::waitKey(5) == 27))
        {
            break;
        }
    }
    Close();
    return 0;
}