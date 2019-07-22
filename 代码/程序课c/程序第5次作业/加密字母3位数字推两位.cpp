#include<cstdio>
#include<cstring>
#include<cctype>
int main()
{
	char s[105];
	gets(s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='X'&&s[i]<='Z'||s[i]>='x'&&s[i]<='z')
			s[i]-=23;
		else if(isalpha(s[i])){
			s[i]+=3;
			//printf("%c\n",s[i]);
		}
		else if(s[i]=='9'||s[i]=='8')
			s[i]-=8;
		else if(isdigit(s[i]))s[i]+=2;
	}
	puts(s);
	return 0;
 } 
