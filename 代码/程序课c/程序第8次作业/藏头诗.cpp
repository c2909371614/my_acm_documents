#include<stdio.h>
#include<string.h>
struct poem{
	char s1[4][20];
	char s2[2][20];
};

int main()
{
	struct poem po={"睦亲何用心，","达命何劳问。","丽锦匹云终，","雅韵与琴清。","霄汉期鸳鸯","曼倩恨见难"};
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
