#include <cv.h>
#include <highgui.h>

int main()
{
	IplImage* img = cvLoadImage("lena.jpg");
	IplImage* green_image;
	green_image = cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
	cvSplit(img, NULL, green_image, NULL, NULL);
	//a.找到并显示绿图
	cvNamedWindow("Prac3-7-g", CV_WINDOW_AUTOSIZE);
	cvShowImage("Prac3-7-g", green_image);
	//b.克隆这个绿图两次
	//注意这个地方不能直接赋值（会共用一块内存,软拷贝），要调用克隆图像的函数（硬拷贝）
	IplImage* clone1 = cvCloneImage(green_image);
	IplImage* clone2 = cvCloneImage(green_image);
	//c.求出最大值和最小值
	double min = 0;
	double max = 0;
	cvMinMaxLoc(green_image, &min, &max);
	printf("Min = %f, Max = %f\n", min, max);

	//d.设置thresh
	//thresh是绿图灰度中值
	double thresh = (max - min) / 2.0;
	cvSet(clone1, cvScalar(thresh));
	
	//e.设置掩码
	cvSetZero(clone2);
	cvCmp(green_image, clone1, clone2, CV_CMP_GE);

	//f.使用cvSubS函数并显示结果
	cvSubS(green_image, cvScalar(thresh / 2.0), green_image, clone2);

	cvNamedWindow("Prac3-7-f", CV_WINDOW_AUTOSIZE);
	cvShowImage("Prac3-7-f", green_image);
	cvWaitKey(0);
	return 0;
}