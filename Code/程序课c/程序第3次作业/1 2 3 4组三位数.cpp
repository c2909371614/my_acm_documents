#include<stdio.h>
int main()
{
	int a,b,c,count=0;
	for(a=1;a<=4;a++)
		for(b=1;b<=4;b++)
			for(c=1;c<=4;c++)
				if(a!=b&&a!=c&&b!=c){
					printf("%d%d%d\n",a,b,c);
					count++;
				}
			printf("%d",count); 
}
