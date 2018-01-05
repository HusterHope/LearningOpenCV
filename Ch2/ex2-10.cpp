#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv)
{
	CvCapture* capture = 0;
	capture = cvCreateFileCapture("test.avi");
	if (!capture)
		return -1;
	//初始化读取视频
	IplImage *bgr_frame = cvQueryFrame(capture);
	double fps = cvGetCaptureProperty(
		capture,
		CV_CAP_PROP_FPS
		);
	CvSize size = cvSize(
		(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
		(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT)
		);
	
	CvVideoWriter *writer = cvCreateVideoWriter(
		"testWriter.avi",//新建视频文件的名称
		CV_FOURCC('M','J','P','G'),//视频压缩的编码格式
		fps,			//播放帧速率
		size			//视频大小
		);
	IplImage* logpolar_frame = cvCreateImage(
		size,
		IPL_DEPTH_8U,
		3
		);
	while ((bgr_frame = cvQueryFrame(capture)) != NULL)
	{
		cvLogPolar(bgr_frame, logpolar_frame,
			cvPoint2D32f(bgr_frame->width / 2, bgr_frame->height / 2),
			40,
			CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS
			);
		cvWriteFrame(writer, logpolar_frame);
	}
	cvReleaseVideoWriter(&writer);
	cvReleaseImage(&logpolar_frame);
	cvReleaseCapture(&capture);
	return 0;
}