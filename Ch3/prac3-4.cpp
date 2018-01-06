// 创建一个3通道RGB图像，绘制绿色平面（与3-3类似）
#include <cv.h>
#include <highgui.h>

int main()
{
	//题目中为100*100的矩阵，这里设为200*200便于观察
	IplImage* img = cvCreateImage(cvSize(200,200), 8, 3);
	cvZero(img);

	//指针法：创建一个用于遍历图像的空指针
	int* ptr = NULL;
	for (int i = 5; i < 20; i++)
	{
		for (int j = 20; j < 40; j++)
		{
			//指针位置：先获取图像第一行位置，再加上行位置和列位置，最后找到绿色所在通道（+1）
			ptr = (int*)(img->imageData + i*img->widthStep + j*img->nChannels + 1);
			//改写通道参数
			*ptr = 255;
		}
	}

	cvNamedWindow("Prac3-4", CV_WINDOW_AUTOSIZE);
	cvShowImage("Prac3-4", img);
	cvWaitKey(0);
	return 0;
}