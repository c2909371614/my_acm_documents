#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char *color[20],str[20];
	int i=0;
	scanf("%s",str);
	while(str[0]!='#'){
		color[i]=(char*)malloc(sizeof(char)*strlen(str));
		if(color[i]==NULL)	puts("apply fail");
		strcpy(color[i++],str);
		scanf("%s",str);
	}
	while(--i>=0)
		puts(color[i]);
	return 0;
}
