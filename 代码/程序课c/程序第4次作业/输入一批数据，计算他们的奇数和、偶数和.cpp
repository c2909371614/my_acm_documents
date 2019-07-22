#include<stdio.h>
int sum1=0,sum2=0;
void sum(int a)
{
	if(a%2!=0)
		sum1+=a;
	else sum2+=a;
}
int main()
{
	int odd,even,integer,n;
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&integer);
		sum(integer);
	}
	printf("sum1=%d sum2=%d",sum1,sum2);
	return 0;
}
