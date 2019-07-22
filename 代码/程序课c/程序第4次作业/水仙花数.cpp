#include<stdio.h>
#include<math.h>
int water_flower(int digit)
{
	int a[105],i,count=0,sum=0;
	int temp=digit;
	for(i=1;;i++){
		a[i]=digit%10;
		count++;
		digit/=10;
		if(!digit)break;
	}
	for(i=1;i<=count;i++)
		sum+=pow(a[i],3);
	if(sum==temp)return temp;
	else return 0;
}
int main()
{
	int n,m,mark;
	scanf("%d%d",&m,&n);
	for(int i=m;i<=n;i++){
		mark=water_flower(i);
		if(mark) printf("water flower:%d\n",mark);
	}
	return 0; 
}
