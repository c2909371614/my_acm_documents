//（6）	编程实现：求文件大小，改文件名，删除一个文件
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void get_size(char f_name1[]){
	FILE *fp;
	if((fp=fopen(f_name1,"r+"))==NULL){
		printf("file open fail\n");
		exit(0);
	}
	char s;
	int size=0;
	while((s=fgetc(fp))!=EOF){
		size++;
	}
	printf("size of the file=%dByte\n",size);
	fclose(fp);
}
void rename_f(char name[]){
	char name2[20];
	printf("enter renamed name:");
	scanf("%s",name2);
	if(rename(name,name2)==0)
		puts("renamed the file");
	else
		puts("rename fail");
}
void del_f(char name[]){
	if(remove(name)==0)
		puts("deleted file");
	else puts("fail");
}
int main()
{
	
	char f_name1[20];
	printf("enter open filename："); 
	scanf("%s",f_name1);
	int chioce;
	puts("1.get the file size\t2.rename the file\t3.delete the file\t0.exit");
	printf("enter your chioce:");
	scanf("%d",&chioce);
	while(chioce){ 
		switch(chioce){
			case 1:get_size(f_name1);break;
			case 2:rename_f(f_name1);break;
			case 3:del_f(f_name1);break;
		}
		puts("1.get the file size\t2.rename the file\t3.delete the file\t0.exit");
		scanf("%d",&chioce);
	} 
 } 
