#include<cstdio>
#include<cctype>
#include<cstring>
int main()
{
	char s[105];
	int upper=0,lower=0,digit=0,empty=0,other=0;
	gets(s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(isupper(s[i]))upper++;
		else if(islower(s[i]))lower++;
		else if(isdigit(s[i]))digit++;
		else if(s[i]==' ')empty++;
		else other++;
	}
	printf("upper=%d lower=%d digit=%d empty=%d other=%d",upper,lower,digit,empty,other);
	return 0;
}
