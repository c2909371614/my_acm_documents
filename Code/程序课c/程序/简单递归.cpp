#include<stdio.h>
int fact(int n){
	return n==0?1:fact(n-1)*n;
} 
int main()
{
	int x;
	
	scanf("%d",&x);
	if(x<0)  printf("invalid");
	else printf("%d",fact(x));
	return 0;
}
