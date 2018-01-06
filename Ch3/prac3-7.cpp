#include <cv.h>
#include <highgui.h>

int main()
{
	IplImage* img = cvLoadImage("lena.jpg");
	IplImage* green_image;
	green_image = cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
	cvSplit(img, NULL, green_image, NULL, NULL);
	//a.�ҵ�����ʾ��ͼ
	cvNamedWindow("Prac3-7-g", CV_WINDOW_AUTOSIZE);
	cvShowImage("Prac3-7-g", green_image);
	//b.��¡�����ͼ����
	//ע������ط�����ֱ�Ӹ�ֵ���Ṳ��һ���ڴ�,��������Ҫ���ÿ�¡ͼ��ĺ�����Ӳ������
	IplImage* clone1 = cvCloneImage(green_image);
	IplImage* clone2 = cvCloneImage(green_image);
	//c.������ֵ����Сֵ
	double min = 0;
	double max = 0;
	cvMinMaxLoc(green_image, &min, &max);
	printf("Min = %f, Max = %f\n", min, max);

	//d.����thresh
	//thresh����ͼ�Ҷ���ֵ
	double thresh = (max - min) / 2.0;
	cvSet(clone1, cvScalar(thresh));
	
	//e.��������
	cvSetZero(clone2);
	cvCmp(green_image, clone1, clone2, CV_CMP_GE);

	//f.ʹ��cvSubS��������ʾ���
	cvSubS(green_image, cvScalar(thresh / 2.0), green_image, clone2);

	cvNamedWindow("Prac3-7-f", CV_WINDOW_AUTOSIZE);
	cvShowImage("Prac3-7-f", green_image);
	cvWaitKey(0);
	return 0;
}