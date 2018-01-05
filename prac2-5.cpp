#include <cv.h>
#include <highgui.h>
#include <math.h>

//第二章练习第5题。

//滚动条位置
int g_scale = 1;


int  main(int argc, char** argv)
{
	CvCapture* capture = NULL;
	cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);
	capture = cvCreateFileCapture("test.avi");
	//获取视频总帧数
	int frames = (int)cvGetCaptureProperty(
		capture,
		CV_CAP_PROP_FRAME_COUNT
		);
	if (frames != 0)
	{
		cvCreateTrackbar(
			"Scale",		//滚动条名称
			"Example3",		//滚动条所属窗口
			&g_scale,
			8,				//滚动条最大值
			NULL	//回调函数，拖动滚动条时调用
			);
	}
	IplImage* frame;
	IplImage* out;
	int i,count;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame)
			break;
		if (g_scale >= 2)
		{
			//由于cvPyrUp和cvPyrDown只能进行放大或缩小2倍的处理，因此求对数以确定缩放次数。
			count = log(g_scale) / log(2);
			for (i = 0; i < count; i++)
			{
				out = cvCreateImage(
					cvSize(frame->width * 2, frame->height * 2),
					frame->depth,
					frame->nChannels
					);
				cvPyrUp(frame, out);
				frame = out;
			}
		}
		cvShowImage("Example3", frame);

		char c = cvWaitKey(33);

		if (c == 27)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example3");
	return(0);
}