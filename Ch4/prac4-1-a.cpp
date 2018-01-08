#include <highgui.h>
#include <cv.h>

int  main(int argc, char** argv)
{
	cvNamedWindow("Prac4-1-1", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Prac4-1-2", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Prac4-1-3", CV_WINDOW_AUTOSIZE);
	//CvCapture 包含了所有与读入视频文件相关的信息
	CvCapture* capture = cvCreateFileCapture("test.avi");
	if (capture == NULL)
		return -1;
	IplImage *f;

	//获取每秒帧数
	int fps = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
	//每帧持续时间
	double t = 1000.0 / fps;
	int fw = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
	int fh = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
	IplImage* grayf = cvCreateImage(cvSize(fw, fh), 8, 1);
	IplImage* cannyf = cvCreateImage(cvSize(fw, fh), 8, 1);
	while (1)
	{
		f = cvQueryFrame(capture);
		if (!f)
			break;
		cvCvtColor(f, grayf, CV_BGR2GRAY);
		cvCanny(f, cannyf, 10, 100, 3);
		cvShowImage("Prac4-1-1", f);
		cvShowImage("Prac4-1-2", grayf);
		cvShowImage("Prac4-1-3", cannyf);
		//cvConvertImage
		char c = cvWaitKey(t);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyAllWindows();
}