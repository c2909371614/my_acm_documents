#include<stdio.h>
#include<string.h>
int main()
{
	char s[105];
	while(scanf("%s",s)!=EOF){
		int len;
		char max;
		len=strlen(s);
		max=0;
		for(int i=1;i<len;i++)
			if(s[max]<s[i])max=i;
		for(int i=0;i<len;i++){
			printf("%c",s[i]);
			if(s[i]==s[max])printf("(max)");
		}
		printf("\n");
	}
	
}
