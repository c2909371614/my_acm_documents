#include<stdio.h>
#include<cctype> 
#include<string.h>
int main()
{
	char a[10005];
	gets(a);
	int len=strlen(a);
	for(int i=0;i<len;i++)
	if(isupper(a[i])) a[i]=tolower(a[i]);
	else if(islower(a[i])) a[i]=toupper(a[i]);
	puts(a); 
	return 0;
 } 
