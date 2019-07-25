#include<bits/stdc++.h>
#define SIZE 3
using namespace std;
struct sysuser{
	char username[20];
	char password[8];
};
int main()
{
	FILE *fp;
	int i;
	struct sysuser u[SIZE],*pu=u,su[SIZE];
	for(i=0;i<SIZE;i++,pu++){
		printf("enter %dth sysuser (name password):",i+1);
		scanf("%s%s",pu->username,pu->password);
	} 
	if((fp=fopen("≤‚ ‘.dat","wb+"))==NULL){
		cout<<"file open fail"<<endl;
		exit(0);
	}
	pu=u;
	fwrite(pu,sizeof(struct sysuser),SIZE,fp);
	rewind(fp);
	fread(su,sizeof(struct sysuser),SIZE,fp);
	for(i=0;i<SIZE;i++)
		printf("%s\n%s",su[i].username ,su[i].password );
	fclose(fp);
}

