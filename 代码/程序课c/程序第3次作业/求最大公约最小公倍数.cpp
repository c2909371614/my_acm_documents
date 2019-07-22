#include<stdio.h>
int main()
{
	int n,m,factor,multiple,bug=0;
	scanf("%d%d",&n,&m);
	if(n>m){
		factor=m;
		multiple=n;
	}
	else {
		factor=n;
		multiple=m;
	}
		for(factor;factor>=1;factor--)
			if(n%factor==0&&m%factor==0){
				printf("%d\n",factor);
				break;				
			}
		for(multiple;;multiple++)
			if(multiple%n==0&&multiple%m==0){
				printf("%d\n",multiple);
				break;
		}
	return 0;
 } 
