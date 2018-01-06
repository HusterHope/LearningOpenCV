#include <cv.h>
#include <highgui.h>

// ��ȡlena��ͼ�񲢽�ROI�������������ֵ����100
// ���ú�����ROI��������ȥ���ӷ��㣬����ROIֻ�ܴ��д����ұ��벻�ϵ����ú�����

int main(int argc, char** argv)
{
	IplImage* src = cvLoadImage("lena.jpg", 1);
	int x = 100;
	int y = 100;
	int width = 240;
	int height = 300;
	//����ROIͼ��ͷ
	IplImage *sub_img = cvCreateImageHeader(
		cvSize(width, height),
		src->depth,
		src->nChannels
		);
	sub_img->origin = src->origin;
	sub_img->widthStep = src->widthStep;
	//ƥ��λ��
	sub_img->imageData = src->imageData +
		y*src->widthStep + 
		x*src->nChannels;
	cvAddS(sub_img, cvScalar(100), sub_img);
	cvReleaseImageHeader(&sub_img);
	cvNamedWindow("Roi_Add", CV_WINDOW_AUTOSIZE);
	cvShowImage("Roi_Add", src);
	cvWaitKey(0);
}