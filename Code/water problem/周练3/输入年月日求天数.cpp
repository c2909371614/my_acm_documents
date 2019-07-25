#include<stdio.h>
int main()
{
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int Y,M,D,n,sum;
	scanf("%d",&n);
	for(int j=1;j<=n;j++) {
		sum=0;
		scanf("%d%d%d",&Y,&M,&D);
		sum+=(Y-1)*365;
		for(int i=1;i<M;i++)
			sum+=a[i];
		sum+=D;
		if(Y%4==0&&Y%100!=0||(Y%400==0))
			sum++;
		printf("%d\n",sum);
	}
	return 0;
 } 
