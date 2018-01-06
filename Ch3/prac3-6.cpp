#include <highgui.h>
#include <cv.h>

int main()
{
	//��ȡһ����С����Ϊ100*100��ͼ��
	IplImage* img = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_COLOR);
	//��������ͼ��ͷ��������origin/depth/nChannels��widthStep
	IplImage* sub_img1 = cvCreateImageHeader(cvSize(20, 30), img->depth, img->nChannels);
	IplImage* sub_img2 = cvCreateImageHeader(cvSize(20, 30), img->depth, img->nChannels);
	sub_img1->origin = img->origin;
	sub_img2->origin = img->origin;
	sub_img1->widthStep = img->widthStep;
	sub_img2->widthStep = img->widthStep;
	//��imageData�ֱ�ָ��(5,10)��(50,60)λ��
	sub_img1->imageData = img->imageData + 10 * sub_img1->widthStep + 5 * sub_img1->nChannels;
	sub_img2->imageData = img->imageData + 60 * sub_img1->widthStep + 50 * sub_img1->nChannels;
	//������������ͼ��ͷ��cvNot
	cvNot(sub_img1, sub_img1);
	cvNot(sub_img2, sub_img2);
	//��ʾ�����ȡ��ͼ��
	cvNamedWindow("Prac3-6", CV_WINDOW_AUTOSIZE);
	cvShowImage("Prac3-6", img);
	cvWaitKey(0);
	return 0;
}