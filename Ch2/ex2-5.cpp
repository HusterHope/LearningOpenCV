#include <cv.h>
#include <highgui.h>

IplImage* doPyrDown(
	IplImage* in,
	int filter
	)
{
	//ȷ������ͼ��ĳ��Ϳ��ܹ���2����
	assert(in->width % 2 == 0 && in->height % 2 == 0);

	IplImage* out = cvCreateImage(
		cvSize(in->width / 2, in->height / 2),
		in->depth,
		in->nChannels
		);
	cvPyrDown(in, out);
	return (out);
}

int main(int argc, char** argv)
{
	IplImage* img = cvLoadImage("lena.jpg",1);
	int filter = IPL_GAUSSIAN_5x5;
	img = doPyrDown(img, filter);
	cvNamedWindow("Example2-5", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example2-5", img);

	cvWaitKey(0);

	cvReleaseImage(&img);
	cvDestroyWindow("Example2-5");
}