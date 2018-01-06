#include <highgui.h>
#include <cv.h>

int main()
{
	//读取一个大小至少为100*100的图像
	IplImage* img = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_COLOR);
	//另创建两个图像头，设置其origin/depth/nChannels和widthStep
	IplImage* sub_img1 = cvCreateImageHeader(cvSize(20, 30), img->depth, img->nChannels);
	IplImage* sub_img2 = cvCreateImageHeader(cvSize(20, 30), img->depth, img->nChannels);
	sub_img1->origin = img->origin;
	sub_img2->origin = img->origin;
	sub_img1->widthStep = img->widthStep;
	sub_img2->widthStep = img->widthStep;
	//将imageData分别指向(5,10)和(50,60)位置
	sub_img1->imageData = img->imageData + 10 * sub_img1->widthStep + 5 * sub_img1->nChannels;
	sub_img2->imageData = img->imageData + 60 * sub_img1->widthStep + 50 * sub_img1->nChannels;
	//传递这两个新图像头给cvNot
	cvNot(sub_img1, sub_img1);
	cvNot(sub_img2, sub_img2);
	//显示最初读取的图像
	cvNamedWindow("Prac3-6", CV_WINDOW_AUTOSIZE);
	cvShowImage("Prac3-6", img);
	cvWaitKey(0);
	return 0;
}