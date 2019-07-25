#include<stdio.h>
int main()
{
	int a,b,c,d,count=0;
	for(a=0;a<=2;a++)
		for(b=0;b<=10;b++)
			for(c=0;c<=20;c++)
				for(d=0;d<=100;d++)
					if(a*50+b*10+c*5+d*1==100){ 
						printf("50:%d 10:%d 5:%d 1:%d\n",a,b,c,d);
						count++;
					} 
	printf("%d",count);
 } 
