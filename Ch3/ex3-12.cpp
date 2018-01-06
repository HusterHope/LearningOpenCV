#include <cv.h>
#include <highgui.h>

//读取lena的图像并将ROI区域的蓝色通道增加100级灰度值

int main(int argc, char** argv)
{
	IplImage* src = cvLoadImage("lena.jpg", 1);
	int x = 100;
	int y = 100;
	int width = 240;
	int height = 300;
	int add = 100;
	cvSetImageROI(src, cvRect(x, y, width, height));
	cvAddS(src, cvScalar(add), src);
	cvResetImageROI(src);
	cvNamedWindow("Roi_Add", 1);
	cvShowImage("Roi_Add", src);
	cvWaitKey(0);
}