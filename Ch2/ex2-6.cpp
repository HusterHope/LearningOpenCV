#include <cv.h>
#include <highgui.h>

IplImage* doCanny(
	IplImage* in,
	double lowThresh,
	double highThresh,
	double aperture
	)
{
	//Canny只能处理单通道图像
	if (in->nChannels != 1)
		return(0);

	IplImage* out = cvCreateImage(
		cvGetSize(in),
		IPL_DEPTH_8U,
		1
		);
	cvCanny(in, out, lowThresh, highThresh, aperture);
	return(out);
}

int main(int argc, char** argv)
{
	//-1:默认读取原图像通道数
	//1:读取彩色图
	//0:强制读取灰度图
	//因为Canny只能处理单通道图像，因此这里将第二个参数置为0
	IplImage* img = cvLoadImage("faceScene.jpg", 0);
	int filter = IPL_GAUSSIAN_5x5;
	img = doCanny(img,10,100,3);
	cvNamedWindow("Example2-6", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example2-6", img);

	cvWaitKey(0);

	cvReleaseImage(&img);
	cvDestroyWindow("Example2-6");
}