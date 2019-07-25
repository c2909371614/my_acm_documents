#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	scanf("%s%s",a,b);
	if(rename(a,b)==0)
		puts("success");
	else perror("rename");
}
