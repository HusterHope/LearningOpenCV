//��֤IPP��İ�װ���
#include <cv.h>

int main(int argc, char** argv)
{
	const char* libraries;
	const char* modules;
	cvGetModuleInfo(0, &libraries, &modules);
	printf("Libraries: %s\nModules:%s\n", libraries, modules);
	getchar();
	return 0;
}