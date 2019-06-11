//#if 0 //运行前改成1
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
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap;
	cap.open(0); //打开摄像头

	if (!cap.isOpened())//如果视频不能正常打开则返回
		return 0;
	cvWaitKey(30);
	Mat frame;//用于保存每一帧图像
	cap >> frame;
	//imshow("frame", frame);
	cvWaitKey(300);
	char buf[100]; //保存路径变量
 	int totalFrame = 200;

	//while (1)
        for(int i = 0; i < totalFrame; ++ i)
	{
		cap >> frame;          //等价于cap.read(frame);
		if (frame.empty())     //如果某帧为空则退出循环
			break;

		imshow("双目原始视图", frame);    //显示双目原始图像  原始分辨率为 640*480

		Mat DoubleImage;

		resize(frame, DoubleImage, Size(640, 240), (0, 0), (0, 0), INTER_AREA);   // 纵向分辨率缩小一半
		imshow("DoubleImage", DoubleImage);  //显示图像


		Mat LeftImage = DoubleImage(Rect(0, 0, 320, 240));      //分割得到左视图
		Mat RightImage = DoubleImage(Rect(320, 0, 320, 240));   //分割得到右视图

		imshow("LeftImage", LeftImage);         //显示左视图
		imshow("RightImage", RightImage);        //显示右视图

		//char c = cvWaitKey(30);
		//if (c == 27)//Esc键退出
		//{
		//	break;                               sprintf(outfile, "//home//fang//视频//图片//%d.png", i);
		                                            //imwrite(outfile, frame);
		                                             //waitKey(100);
		//}

		//static int i = 0;
		//if (13 == char(c))  
               // int i = 0;
		//for( ; i < totalFrame; ++ i)                                
		//{
			sprintf(buf, "//home//fang//picture//left_%d.png", i);  //保存左视图"//home//fang//视频//图片//%d.png", i    //home//fang//picture//left_%d.png"
			//cout << buf;
			imwrite(buf, LeftImage);
			//waitKey(100);


			sprintf(buf, "//home//fang//picture//right_%d.png", i);  //保存右视图
			imwrite(buf, RightImage);
			//waitKey(100);


			sprintf(buf, "//home//fang//picture//total_%d.png", i);  //保存整体图像
			imwrite(buf, DoubleImage);
			//i++;
			waitKey(100);
		//}
		
		

	}
	cap.release();//释放资源
        return 0;
}

//运行此程序g++ cap_image.cpp -o cap_image `pkg-config --cflags --libs opencv`
//#endif
