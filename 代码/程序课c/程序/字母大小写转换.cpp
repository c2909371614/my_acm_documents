#include<stdio.h>
int main()
{
	char pi;
	int i;
	for(i=1;i<=5;i++){
		pi=getchar();
		if('a'<=pi&&pi<='z')
		pi=pi-32;
		else if('A'<=pi&&pi<='Z')
		pi=pi+32;
		putchar(pi);
	}
	return 0;
 } 
