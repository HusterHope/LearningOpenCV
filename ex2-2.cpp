#include <highgui.h>

int  main(int argc, char** argv)
{
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	//CvCapture 包含了所有与读入视频文件相关的信息
	CvCapture* capture = cvCreateFileCapture("test.avi");
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame)
			break;
		cvShowImage("Example2", frame);
		//每秒30帧，每帧时间约为33ms
		//这种控制方法不是很精确，更好的方法是从CvCapture结构中读取。
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
}