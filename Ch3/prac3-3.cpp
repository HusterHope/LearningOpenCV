//ͨ������cvPtr2D��ָ��ָ���м��ͨ������ɫ������ͼ
#include <cv.h>
#include <highgui.h>

int main()
{
	//��Ŀ��Ϊ100*100�ľ���������Ϊ200*200���ڹ۲�
	CvMat* mat = cvCreateMat(200, 200, CV_8UC3);
	cvZero(mat);
	
	int* pt = NULL;
	//�ֱ𻭳����±߿�����ұ߿�
	for (int i = 20; i <= 40; i++)
	{
		pt = (int*)cvPtr2D(mat, 5, i, NULL);
		//ȡ����ɫͨ��(ͨ������ΪB,G,R)
		pt++;
		//����ͨ������ֵ��дΪ255�����ֵ��
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