#include <cv.h>
#include <highgui.h>

// 读取lena的图像并将ROI区域的所有像素值增加100
// 设置和重置ROI方法看上去更加方便，但是ROI只能串行处理并且必须不断地设置和重置

int main(int argc, char** argv)
{
	IplImage* src = cvLoadImage("lena.jpg", 1);
	int x = 100;
	int y = 100;
	int width = 240;
	int height = 300;
	//创建ROI图像头
	IplImage *sub_img = cvCreateImageHeader(
		cvSize(width, height),
		src->depth,
		src->nChannels
		);
	sub_img->origin = src->origin;
	sub_img->widthStep = src->widthStep;
	//匹配位置
	sub_img->imageData = src->imageData +
		y*src->widthStep + 
		x*src->nChannels;
	cvAddS(sub_img, cvScalar(100), sub_img);
	cvReleaseImageHeader(&sub_img);
	cvNamedWindow("Roi_Add", CV_WINDOW_AUTOSIZE);
	cvShowImage("Roi_Add", src);
	cvWaitKey(0);
}