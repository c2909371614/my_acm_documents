#include<stdio.h>
int main()
{
	int n,i,j,a[100],A[100];
	for(i=0;i<100;i++)
		A[i]=a[i]=1;//printf("%d ",a[i]);
	scanf("%d",&n);
	for(i=1;i<n;i++)
		printf(" ");
	printf("1\n");
	for(i=1;i<n;i++){//i+1Îª²ãÊý 
		for(int k=1;k<n-i;k++)
			printf(" ");
		for(j=1;j<=i+1;j++){
			if(j!=1&&j!=i+1)
				a[j]=A[j-1]+A[j] ;
			printf("%d ",a[j]);
		}
		printf("\n");
		for(j=1;j<=i+1;j++)
			A[j]=a[j];
	}	
	return 0;
 } 
