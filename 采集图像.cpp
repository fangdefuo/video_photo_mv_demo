#include<iostream>
#include <iostream>
#include<opencv2/opencv.hpp>
#include <string>
#include <io.h>
//#include <opencv2\ml.hpp>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



 
using namespace std;
using namespace cv;
using namespace ml;

int main()
{
        VideoCapture Camera(0);
        if (!Camera.isOpened())
        {
                cout << "Could not open the Camera " << endl;
                return -1;
        }
        Mat Fream;
        Mat DoubleImage;


        while (true)
        {
                Camera >> Fream;
                if (Fream.empty()) break;
                resize(Fream, DoubleImage, Size(640, 240), (0, 0), (0, 0), INTER_AREA);
                imshow("【双目视图】", DoubleImage);
                Mat     LeftImage = DoubleImage(Rect(0, 0, 320, 240));
                Mat RightImage = DoubleImage(Rect(320, 0, 320, 240));

                imshow("【左视图】", LeftImage);
                imshow("【右视图】", RightImage);
                char key = waitKey(30);

                char c = cvWaitKey(30);
                if (c == 27)//Esc键退出
                {
                        break;
                }
        }
        return 0;
}



//运行此程序g++ two_video.cpp -o two_video `pkg-config --cflags --libs opencv`



