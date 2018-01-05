#include <cv.h>
#include <highgui.h>

//滚动条位置
int g_slider_position = 0;
//"g_" 代表全局变量(global)
CvCapture* g_capture = NULL;

void onTrackbarSlide(int pos)
{
	cvSetCaptureProperty(
		g_capture,
		CV_CAP_PROP_POS_FRAMES,
		//CV_CAP_PROP_POS_AVI_RATIO,
		pos
	);
}

int  main(int argc, char** argv)
{
	cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture("test.avi");
	//获取视频总帧数
	int frames = (int)cvGetCaptureProperty(
		g_capture,
		CV_CAP_PROP_FRAME_COUNT
		);
	if (frames != 0)
	{
		cvCreateTrackbar(
			"Position",//滚动条名称
			"Example3",//滚动条所属窗口
			&g_slider_position,
			frames,//滚动条最大值
			onTrackbarSlide//回调函数，拖动滚动条时调用
			);
	}
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(g_capture);
		if (!frame)
			break;
		cvShowImage("Example3", frame);
		//每秒30帧，每帧时间约为33ms
		//这种控制方法不是很精确，更好的方法是从CvCapture结构中读取。
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&g_capture);
	cvDestroyWindow("Example3");
	return(0);
}