#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	time_t t;
	t=time(NULL);
	struct tm *p;//tm 是 time.h头文件中定义的一个结构体其中变量存在范围 
	p=localtime(&t);
	printf("%d.%d.%d %d:%d:%d\n",
	p->tm_year+1900,p->tm_mon+1,p->tm_mday
	,p->tm_hour,p->tm_min,p->tm_sec);
}
