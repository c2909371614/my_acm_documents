/*��4��	һ���ṹ����{������Ӣ���ѧ��C����}��
����fwriteд��һ���ļ��У��������ļ�����������n����fwrite������n����¼ֵ*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 4
void fail_1(){
	printf("fail\n");
	exit(0);
}
struct ss{
	char name[10];
	int English;
	int math;
	int c_lang;
};
int main()
{
	struct ss score[N],*sp=score,read;
	int i,n;
	FILE *fp;
	if((fp=fopen("name_score.cpp","wb+"))==NULL)
		fail_1();
	puts("enter name English math c_lang:");
	for(i=0;i<N;i++,sp++)
		scanf("%s%d%d%d",sp->name ,&sp->English ,&sp->math ,&sp->c_lang );
	if(!fwrite(score,sizeof(score),1,fp))
		fail_1();
	puts("enter n ");
	scanf("%d",&n);
	rewind(fp);
	if(fseek(fp,sizeof(struct ss)*(n-1),0))
		fail_1();
	fread(&read,sizeof(struct ss),1,fp);
	puts("name\tEnglish\tmath\tc_lang");
	printf("%s\t%d\t%d\t%d\n",read.name ,read.English ,read.math ,read.c_lang );
	fclose(fp);
}
