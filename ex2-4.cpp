#include <cv.h>
#include <highgui.h>

//对输入图像做平滑，用两个窗口分别显示平滑前后的图像
void example2_4(IplImage* image)
{
	//创建展示输入和输出的窗口
	cvNamedWindow("Example4-in");
	cvNamedWindow("Example4-out");

	cvShowImage("Example4-in", image);

	//分配图像结构空间用来存储平滑处理后的图像
	IplImage* out = cvCreateImage(
		cvGetSize(image),		//cvSize结构
		IPL_DEPTH_8U,			//每个像素的数据类型
		3						//通道总数
		);

	//平滑处理
	cvSmooth(image, out, CV_GAUSSIAN, 3, 3);
	//在输出窗口中显示平滑后的图像
	cvShowImage("Example4-out", out);
	cvReleaseImage(&out);
}

int  main(int argc, char** argv)
{
	//CvCapture 包含了所有与读入视频文件相关的信息
	CvCapture* capture = cvCreateFileCapture("test.avi");
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame)
			break;
		example2_4(frame);
		//每秒30帧，每帧时间约为33ms
		//这种控制方法不是很精确，更好的方法是从CvCapture结构中读取。
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyAllWindows();
}