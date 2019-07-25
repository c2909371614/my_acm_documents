#include<stdio.h>
int main()
{
	int a[10];
	int min,i,temp,n;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<9;i++){
		min=i;
		for(n=i+1;n<10;n++)
		   if(a[n]<a[min])
		      min=n;
		temp=a[min];   
	    a[min]=a[i];
	    a[i]=temp;
	}
	for(i=1;i<10;i++)
	   printf("%d\t",a[i]);
	return 0;
 } 
