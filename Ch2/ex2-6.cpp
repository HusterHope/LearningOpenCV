#include <cv.h>
#include <highgui.h>

IplImage* doCanny(
	IplImage* in,
	double lowThresh,
	double highThresh,
	double aperture
	)
{
	//Cannyֻ�ܴ���ͨ��ͼ��
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
	//-1:Ĭ�϶�ȡԭͼ��ͨ����
	//1:��ȡ��ɫͼ
	//0:ǿ�ƶ�ȡ�Ҷ�ͼ
	//��ΪCannyֻ�ܴ���ͨ��ͼ��������ｫ�ڶ���������Ϊ0
	IplImage* img = cvLoadImage("faceScene.jpg", 0);
	int filter = IPL_GAUSSIAN_5x5;
	img = doCanny(img,10,100,3);
	cvNamedWindow("Example2-6", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example2-6", img);

	cvWaitKey(0);

	cvReleaseImage(&img);
	cvDestroyWindow("Example2-6");
}