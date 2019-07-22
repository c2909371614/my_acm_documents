#include<stdio.h>
#include<math.h>
int main()
{
	int digit,i,j;
	int a[1005];
	scanf("%d",&digit);
	
	int m=2;
	int count=0;
	for(i=0;i<1000;i++)
		a[i]=1;
	while(m<=sqrt(1000)){
		//if(!a[i*m])continue;
		for(i=2;i*m<1000;i++)
			a[i*m]=0;
		m++;
	}
	
	for(j=2;j<=digit;j++){
		int count=0;
		for(i=2;i<=digit;i++)
			if(a[i]&&a[j]&&j+i==digit){
				printf("%d+%d=%d \n",i,j,digit);
				count=1;
				break;
			}
		if(count)break;
	}
	return 0;
}
