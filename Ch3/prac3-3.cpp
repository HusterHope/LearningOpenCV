//通过函数cvPtr2D将指针指向中间的通道（绿色）并绘图
#include <cv.h>
#include <highgui.h>

int main()
{
	//题目中为100*100的矩阵，这里设为200*200便于观察
	CvMat* mat = cvCreateMat(200, 200, CV_8UC3);
	cvZero(mat);
	
	int* pt = NULL;
	//分别画出上下边框和左右边框
	for (int i = 20; i <= 40; i++)
	{
		pt = (int*)cvPtr2D(mat, 5, i, NULL);
		//取得绿色通道(通道次序为B,G,R)
		pt++;
		//将该通道下数值改写为255（最大值）
		*pt = 255;
		pt = (int*)cvPtr2D(mat, 20, i, NULL);
		pt++;
		*pt = 255;
	}
	for (int j = 5; j <= 20; j++)
	{
		pt = (int*)cvPtr2D(mat, j, 20, NULL);
		pt++;
		*pt = 255;
		pt = (int*)cvPtr2D(mat, j, 40, NULL);
		pt++;
		*pt = 255;
	}
	cvNamedWindow("Prac3-3", CV_WINDOW_AUTOSIZE);
	cvShowImage("Prac3-3", mat);
	cvWaitKey(0);
	return 0;
}