#include<opencv2/opencv.hpp>
#include<iostream>
 
using namespace std;
using namespace cv;
 
int main(int argc,char **argv)
{
	VideoCapture capture(0);
	namedWindow("slamtest",CV_WINDOW_AUTOSIZE);
        char outfile[100];
        int totalFrame = 50;
	for(int i = 1; i<=totalFrame; i++)//while(true)
	{	
		Mat frame;
		capture>>frame;
		//l = &frame
		//cvSetCaptureProperty(l,CV_CAP_PROP_FRAME_WIDTH,320);
		//cvSetCaptureProperty(l,CV_CAP_PROP_FRAME_HEIGHT,240);
		imshow("slamtest",frame);
		//imshow("slamtest",*l);
		sprintf(outfile, "//home//fang//视频//图片//%d.png", i);
		imwrite(outfile, frame);
		waitKey(100);
	}
	return 0;
}



//运行此程序g++ video_photo.cpp -o video_photo `pkg-config --cflags --libs opencv`

