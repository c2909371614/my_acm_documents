#include<stdio.h>
int main()
{
	char pi[200];
	int i,count=0;
	while(scanf("%c",&pi[0])!=EOF){
	
	pi[0]=pi[0]-32;
	for(i=1;i<100;i++){
		scanf("%c",pi[i]);
		if(pi[i]=='\n')break;
	    count++;
	}
	for(i=1;1<100;i++)
	if(pi[i]==' ') pi[i+1]=pi[i+1]-32;
	for(i=0;i<count;i++)
	printf("%c",pi[i]);
	}
	return 0;
}
