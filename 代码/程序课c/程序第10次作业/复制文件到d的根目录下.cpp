#include<stdio.h> 
#include<string.h>
#include<stdlib.h> 
int main()
{
	FILE *fp1,*fp2;
	char name1[20],name2[20]="d:\\";
	puts("enter file name:");
	scanf("%s",name1);
	strcat(name2,name1);
	if((fp1=fopen(name1,"rb"))==NULL){
		puts("file open fail");
		exit(0);
	}
	if((fp2=fopen(name2,"wb"))==NULL){
		puts("file open fail");
		exit(0);
	}
	char ch;
	while((ch=fgetc(fp1))!=EOF)
		fputc(ch,fp2);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
