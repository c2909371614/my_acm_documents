#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int n,*p;
	scanf("%d",&n);
	if((p=(int *)calloc(n,sizeof(int)))=NULL){
		printf("Not able to allocate memory");
		exit(1);
	}
	puts("allocate memery successful");
	struct a13_605{
	char muda[100]="Éµ±Æ";
	char xielaoban[100]="²»´©¿ã×Ó"; 
	char str[100];
};
	struct a13_605 s1;
	scanf("%s",s1.str);
	//gets(s1.str);
	if(strcmp(s1.str,"muda")==0)
		printf("%s\n%s",s1.muda,s1.xielaoban);
 } 
