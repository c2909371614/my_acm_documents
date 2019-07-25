#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int i,j,lenth;
	while(scanf("%s",a)!=EOF){
		lenth=strlen(a);//lenth+1
		//printf("%d  ",lenth);
	 	for(i=0;i<lenth;){
			printf("%s",a+i); 
			if(('a'<=a[i]&&a[i]<='z')||('A'<=a[i]&&a[i]<='Z')||('0'<=a[i]&&a[i]<='9'))i++;
			else i+=2;					
			printf("~\n");
		}			 
	}
	return 0;
}
