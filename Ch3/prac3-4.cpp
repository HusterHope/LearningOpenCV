// ����һ��3ͨ��RGBͼ�񣬻�����ɫƽ�棨��3-3���ƣ�
#include <cv.h>
#include <highgui.h>

int main()
{
	//��Ŀ��Ϊ100*100�ľ���������Ϊ200*200���ڹ۲�
	IplImage* img = cvCreateImage(cvSize(200,200), 8, 3);
	cvZero(img);

	//ָ�뷨������һ�����ڱ���ͼ��Ŀ�ָ��
	int* ptr = NULL;
	for (int i = 5; i < 20; i++)
	{
		for (int j = 20; j < 40; j++)
		{
			//ָ��λ�ã��Ȼ�ȡͼ���һ��λ�ã��ټ�����λ�ú���λ�ã�����ҵ���ɫ����ͨ����+1��
			ptr = (int*)(img->imageData + i*img->widthStep + j*img->nChannels + 1);
			//��дͨ������
			*ptr = 255;
		}
	}

	cvNamedWindow("Prac3-4", CV_WINDOW_AUTOSIZE);
	cvShowImage("Prac3-4", img);
	cvWaitKey(0);
	return 0;
}