#include<stdio.h>
int main()
{
	int money;
	money=10*(1+0.44);
	for(int i=1;i<28;i++){
	
		money=money*(0.1+1);
	printf("%d ",money);
	}
}
