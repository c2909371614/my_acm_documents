#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	int num;
	char name[20];
	int i,score;
	int avg_score=0;
	if((fp=fopen("d:\\新建文件夹\\f12-1.txt","r"))==NULL){
		printf("can't open the file\n");
		exit(0);
	}
	for(i=0;i<2;i++){
		fscanf(fp,"%d%s%d",&num,name,&score);
		avg_score+=score;
		printf("%d %s %d\n",num,name,score);
	}
	printf("aver=%d\n",avg_score/2);
	if(fclose(fp)){
		printf("con not close the file\n");
		exit(0);
	}
	return 0;
}
