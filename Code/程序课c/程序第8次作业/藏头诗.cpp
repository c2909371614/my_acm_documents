#include<stdio.h>
#include<string.h>
struct poem{
	char s1[4][20];
	char s2[2][20];
};

int main()
{
	struct poem po={"���׺����ģ�","���������ʡ�","����ƥ���գ�","���������塣","������ԧ��","��ٻ�޼���"};
	char head[20];
	int i,j;
	for(i=0,j=0;i<4;i++)
		puts(po.s1[i]);
	puts("the key:");
	for(i=0,j=0;i<4;i++){
		head[j+i*2]=po.s1[i][j];
		head[j+1+i*2]=po.s1[i][j+1];
	}
	head[j+i*2]=0;
	puts(head);
	puts("");
	for(i=0,j=0;i<2;i++)
		puts(po.s2[i]);
	puts("the key:");
	for(i=0,j=0;i<2;i++){
		head[j+i*2]=po.s2[i][j];
		head[j+1+i*2]=po.s2[i][j+1];
	}
	head[j+i*2]=0;
	puts(head);	
 } 
