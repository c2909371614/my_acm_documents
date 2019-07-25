#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void fail_1(){
	printf("file open fail\n");
	exit(0);
}
int main()
{ 
 FILE *fp,*ft;
    char set[20];
    int index=0;
    printf("请输入要删除的教师用户名：");
    scanf("%s",set);
    char key[20];
    if((fp=fopen("t_key.txt","r+"))==NULL)
    	fail_1();
	if((ft=fopen("temp.txt","w"))==NULL)
		fail_1();
    while(fgets(key,5,fp)!=NULL){
        if(strcmp(key,set)!=0){
           fputs(key,ft);
           index++;
        }
        else{
            rewind(fp);
            fseek(fp,sizeof(key)*(index+1),0);
        }
    }
        fclose(fp);
        fclose(ft);
        if(remove("t_key.txt")==0)
			printf("remove success\n");
        rename("temp.txt","t_key.txt");
        printf("教师信息删除成功！\n");
}


