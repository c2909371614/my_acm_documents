#include<stdio.h>
#include<string.h>
#include<ctype.h> 
int main()
{
	char a[1000],n=0;
	bool flag=true;
	gets(a);
	int len=strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]==' '||a[i]=='.'||a[i]==','||a[i]=='!'||a[i]=='?')flag=true;
		else {
			if(isalpha(a[i])&&flag)n++;
			flag=false;
		}
	}
	printf("%d",n);
	return 0;
	
}
