#include "opencv2/opencv.hpp"
#include "cartoon.h"

#if !defined VK_ESCAPE
    #define VK_ESCAPE 0x1B
#endif

int main(int argc, char *argv[])
{
    int cameraNumber = 0;
    if (argc > 1)
        cameraNumber = atoi(argv[1]);

    cv::VideoCapture camera(cameraNumber);
    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not access the camera or video!" << std::endl;
        exit(1);
    }

    camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

    while (true)
    {
        cv::Mat frame;
        camera >> frame;
        if (frame.empty()) {
            std::cerr << "ERROR: Could not grab a camera frame." <<
            std::endl;
            exit(1);
        }

        cv::Mat displayed(frame.size(), CV_8UC3);
        cartoonifyImage(frame, displayed);
        imshow("Cartoonifier", displayed);

        char keypress = cv::waitKey(1000/50);
        if (keypress == VK_ESCAPE) {
            break;
        }
    }

    return 0;
}
