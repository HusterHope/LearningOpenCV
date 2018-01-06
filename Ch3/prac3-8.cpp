#include <cv.h>
#include <highgui.h>
#include <string.h>

using namespace std;

//����һ���ṹ������һ��������һ��CvPoint��һ��CvRect
//�ƽṹΪ"my_struct"
typedef struct my_struct
{
	int num;
	CvPoint p;
	CvRect r;
}my_struct;

//д�����ļ�
void write_my_struct(CvFileStorage * fs, const char* name, my_struct *ms)
{
	fs = cvOpenFileStorage(name, 0, CV_STORAGE_WRITE);
	string nName,pName,rName;
	char *snName = NULL;
	char *spName = NULL;
	char *srName = NULL;
	//ע�⣬Ϊ��ʹcvReadIntByName������������Ҫ��ÿ�������ò�ͬ��nameTag�����ļ���
	for (int i = 0; i < 10; i++)
	{
		//�ַ���������ƴ��
		nName = "Num" + to_string(i);
		snName = (char*)nName.c_str();
		cvWriteInt(fs, snName, ms[i].num);
		//CV_NODE_SEQ�ڲ��������ܴ����ƣ����ڶ�������ֱ����Ϊ0��
		pName = "Point" + to_string(i);
		spName = (char*)pName.c_str();
		cvStartWriteStruct(fs, spName, CV_NODE_SEQ);
		cvWriteInt(fs, 0, ms[i].p.x);
		cvWriteInt(fs, 0, ms[i].p.y);
		cvEndWriteStruct(fs);
		rName = "Rect" + to_string(i);
		srName = (char*)rName.c_str();
		cvStartWriteStruct(fs, srName, CV_NODE_SEQ);
		cvWriteInt(fs, 0, ms[i].r.x);
		cvWriteInt(fs, 0, ms[i].r.y);
		cvWriteInt(fs, 0, ms[i].r.width);
		cvWriteInt(fs, 0, ms[i].r.height);
		cvEndWriteStruct(fs);
	}
	cvReleaseFileStorage(&fs);
}

//�������ļ�
void read_my_struct(CvFileStorage *fs, const char* name, my_struct* ms)
{
	fs = cvOpenFileStorage(name, 0, CV_STORAGE_READ);
	int numR, pxR, pyR, rxR, ryR, rwR, rhR;
	CvSeq* s = NULL;
	string nName, pName, rName;
	char *snName = NULL;
	char *spName = NULL;
	char *srName = NULL;
	
	for (int i = 0; i < 10; i++)
	{
		nName = "Num" + to_string(i);
		snName = (char*)nName.c_str();
		numR = cvReadIntByName(fs, 0, snName, 100);
		pName = "Point" + to_string(i);
		spName = (char*)pName.c_str();
		s = cvGetFileNodeByName(fs, 0, spName)->data.seq;
		pxR = cvReadInt((CvFileNode*)cvGetSeqElem(s, 0));
		pyR = cvReadInt((CvFileNode*)cvGetSeqElem(s, 1));
		rName = "Rect" + to_string(i);
		srName = (char*)rName.c_str();
		s = cvGetFileNodeByName(fs, 0, srName)->data.seq;
		rxR = cvReadInt((CvFileNode*)cvGetSeqElem(s, 0));
		ryR = cvReadInt((CvFileNode*)cvGetSeqElem(s, 1));
		rwR = cvReadInt((CvFileNode*)cvGetSeqElem(s, 2));
		rhR = cvReadInt((CvFileNode*)cvGetSeqElem(s, 3));
		printf("num = %d, px = %d, py = %d, rx = %d, ry = %d, rw = %d, rh = %d\n", numR, pxR, pyR, rxR, ryR, rwR, rhR);
	}
}

int main()
{
	my_struct ms[10];
	for (int i = 0; i < 10; i++)
		ms[i] = { i, cvPoint(i, i), cvRect(i, i, 10, 10) };
	CvFileStorage* fs = NULL;
	
	write_my_struct(fs, "cfg.xml", ms);
	read_my_struct(fs, "cfg.xml", ms);

	getchar();
	return 0;
}