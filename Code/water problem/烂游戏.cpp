#include<stdio.h>
int main()
{
	int x,y,count,i,k,a[4];
	scanf("%d",&x);
	for(y=x+1;;y++){
		count=0;
		a[0]=y/1000;
		a[1]=(y-a[0]*1000)/100;
		a[2]=(y-a[0]*1000-a[1]*100)/10;
		a[3]=y%10;
		for(i=0;i<4;i++)
			for(k=i+1;k<4;k++)
				if(a[i]==a[k])count++;
		if(count==0){
			printf("%d\n",y);
			break;
		}
	}
}
