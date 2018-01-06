// ����ROI��cvSet���й��ɵĵ���ͼ
#include <cv.h>
#include <highgui.h>

int main()
{
	//����һ��210*210�ĵ�ͨ��ͼ�񲢽������
	IplImage* img = cvCreateImage(cvSize(210, 210), 8, 1);
	cvZero(img);
	int x, y, width, height;
	for (int i = 1; i <= 10; i++)
	{
		x = 10*i;
		y = 0;
		width = 10;
		height = 20 * i;
		cvSetImageROI(img, cvRect(x, y, width, height));
		cvSet(img, cvScalar(255), NULL);
		cvResetImageROI(img);
	}

	cvNamedWindow("Prac3-5", CV_WINDOW_AUTOSIZE);
	cvShowImage("Prac3-5", img);
	cvWaitKey(0);
	return 0;
}