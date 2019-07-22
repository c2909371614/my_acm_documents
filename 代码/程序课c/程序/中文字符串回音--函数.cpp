#include<stdio.h>
#include<string.h>
char a[100];
int i,j,lenth;
void fun()
{
	for(i=0;i<lenth;){
			printf("%s",a+i); 
			if(('a'<=a[i]&&a[i]<='z')||('A'<=a[i]&&a[i]<='Z')||('0'<=a[i]&&a[i]<='9'))i++;
			else i+=2;					
			printf("~\n");
		}
}
int main()
{
	
	while(scanf("%s",a)!=EOF){
		lenth=strlen(a);//lenth+1
		//printf("%d  ",lenth);
	 	fun();			 
	}
	return 0;
}
