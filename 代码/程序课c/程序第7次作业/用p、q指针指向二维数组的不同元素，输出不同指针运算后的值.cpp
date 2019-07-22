//1.用p、q指针指向二维数组的不同元素，输出不同指针运算后的值，如p+5，p-q，验证按行存储思想,不同数据类型的存储空间大小等
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	int a[10][10],i,j;
//	double b[10];
//	char s[10];
	int *p=&a[0][0],*q=&a[1][0];
	puts("enter a[3][3]:");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	printf("%d %d\n",*(p+2),*p-*q);
	printf("int=%d double=%d char=%d",sizeof(int),sizeof(double),sizeof(char));
	return 0;
 } 
