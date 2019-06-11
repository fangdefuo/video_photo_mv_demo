//#if 0 //����ǰ�ĳ�1
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
	cap.open(0); //������ͷ

	if (!cap.isOpened())//�����Ƶ�����������򷵻�
		return 0;
	cvWaitKey(30);
	Mat frame;//���ڱ���ÿһ֡ͼ��
	cap >> frame;
	//imshow("frame", frame);
	cvWaitKey(300);
	char buf[100]; //����·������
 	int totalFrame = 200;

	//while (1)
        for(int i = 0; i < totalFrame; ++ i)
	{
		cap >> frame;          //�ȼ���cap.read(frame);
		if (frame.empty())     //���ĳ֡Ϊ�����˳�ѭ��
			break;

		imshow("˫Ŀԭʼ��ͼ", frame);    //��ʾ˫Ŀԭʼͼ��  ԭʼ�ֱ���Ϊ 640*480

		Mat DoubleImage;

		resize(frame, DoubleImage, Size(640, 240), (0, 0), (0, 0), INTER_AREA);   // ����ֱ�����Сһ��
		imshow("DoubleImage", DoubleImage);  //��ʾͼ��


		Mat LeftImage = DoubleImage(Rect(0, 0, 320, 240));      //�ָ�õ�����ͼ
		Mat RightImage = DoubleImage(Rect(320, 0, 320, 240));   //�ָ�õ�����ͼ

		imshow("LeftImage", LeftImage);         //��ʾ����ͼ
		imshow("RightImage", RightImage);        //��ʾ����ͼ

		//char c = cvWaitKey(30);
		//if (c == 27)//Esc���˳�
		//{
		//	break;                               sprintf(outfile, "//home//fang//��Ƶ//ͼƬ//%d.png", i);
		                                            //imwrite(outfile, frame);
		                                             //waitKey(100);
		//}

		//static int i = 0;
		//if (13 == char(c))  
               // int i = 0;
		//for( ; i < totalFrame; ++ i)                                
		//{
			sprintf(buf, "//home//fang//picture//left_%d.png", i);  //��������ͼ"//home//fang//��Ƶ//ͼƬ//%d.png", i    //home//fang//picture//left_%d.png"
			//cout << buf;
			imwrite(buf, LeftImage);
			//waitKey(100);


			sprintf(buf, "//home//fang//picture//right_%d.png", i);  //��������ͼ
			imwrite(buf, RightImage);
			//waitKey(100);


			sprintf(buf, "//home//fang//picture//total_%d.png", i);  //��������ͼ��
			imwrite(buf, DoubleImage);
			//i++;
			waitKey(100);
		//}
		
		

	}
	cap.release();//�ͷ���Դ
        return 0;
}

//���д˳���g++ cap_image.cpp -o cap_image `pkg-config --cflags --libs opencv`
//#endif
