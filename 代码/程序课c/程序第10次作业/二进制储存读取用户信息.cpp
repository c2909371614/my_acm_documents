#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define SIZE 3
struct sysuser{
	char username[20];
	char password[8];
};
void encrypt(char* pwy);
int main()
{
	FILE *fp;
	int i;
	struct sysuser u[SIZE],su[SIZE],*pu=u,*psu=su;
	/*���ļ��������������ļ����ж�д��ʽ*/
	char doc_n[20],doc_w[20];
	scanf("%s%s",doc_n,doc_w); 
	if((fp=fopen(doc_n,doc_w))==NULL){
		printf("File open fail");
		exit(0);
	}  
	/*����size���û���Ϣ������������ܣ����浽�ṹ����u*/
	for(i=0;i<SIZE;i++,pu++){
		printf("enter %dth sysuser (name password):",i+1);
		scanf("%s%s",pu->username,pu->password);
		encrypt(pu->password);
		//fprintf(fp,"%s %s\n",pu->username,pu->password);
	} 
	pu=u;
	if(fwrite(pu,sizeof(struct sysuser),SIZE,fp)!=SIZE)
	puts("write fail");  
	rewind(fp);
	if(fread(psu,sizeof(struct sysuser),SIZE,fp)!=SIZE)
		puts("read fail");//��ȡ�������ļ���psu 
	psu=su;
	for(i=0;i<SIZE;i++,psu++){
		printf("%s %s\n",psu->username ,psu->password );
		}
		fclose(fp); 
}
 void encrypt(char *pwy){
	int i;
	for(i=0;i<strlen(pwy);i++)
		pwy[i]^=15;
}

