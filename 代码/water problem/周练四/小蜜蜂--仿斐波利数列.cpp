#include<stdio.h>

int main()
{
	long long mark[51];
	int n,a,b;
	mark[1]=1;mark[2]=2;
	for(int i=3;i<51;i++)
		mark[i]=mark[i-1]+mark[i-2];
		scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		printf("%lld\n",mark[b-a]);
	}
	return 0;
 } 
