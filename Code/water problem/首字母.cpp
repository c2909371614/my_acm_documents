#include<stdio.h>

int main()
{
	char pi[1000];
	int i,count;
	while(scanf("%c",&pi[0])!=EOF){
	count=0;
	pi[0]=pi[0]-32;
	for(i=1;i<1000;i++){
		pi[i]=getchar();
		if(pi[i]=='\n')break;
		count++;
		}
		
	for(i=1;i<1000;i++)
		if(pi[i]==' ') pi[i+1]=pi[i+1]-32;
	for(i=0;i<=count;i++)
		putchar(pi[i]);
		printf("\n");
}
	return 0;
}

