#include<stdio.h>
int main()
{
	int a[5];
	int i,j,temp,max=0,min=0;
	double average,sum=0;
	for(i=0;i<5;i++){
	    scanf("%d",&a[i]);
	    sum=sum+a[i];
        }
	for(j=1;j<5;j++){
		if(a[j]>a[max])
			max=j;
		if(a[j]<a[min]) 
			min=j;
		}
	average=(sum-a[min]-a[max])/3.0;
	printf("average=%.2f ",average);
	printf("%d %d\n",a[min],a[max]);
	return 0;
	}
 
  
