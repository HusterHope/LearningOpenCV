#include <highgui.h>

int main(int argc, char** argv)
{
	IplImage* img = cvLoadImage("lena.jpg",1);
	//Ҳ����ʹ��������ʽ������Ҫ�� ��Ŀ-����-��������-����-������� ����дͼƬλ�ã�
	//IplImage* img = cvLoadImage(argv[1]);
	
	//ָ�����ڱ���ʹ�С
	//CV_WINDOW_AUTOSIZE ��ʾ�ô��ڴ�С��ӦԭʼͼƬ
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1", img);
	//�ȴ��û�����
	//����Ϊָ����������������0Ϊ���޵ȴ�
	cvWaitKey(0);
	//��������Ӧ�ó������ʱ��Ӧ��Դ���ɲ���ϵͳ�Զ��ͷ�
	//��������ϰ�ߣ��ڳ�������ʽ�ͷ����кô���
	cvReleaseImage(&img);
	cvDestroyWindow("Example1");
}