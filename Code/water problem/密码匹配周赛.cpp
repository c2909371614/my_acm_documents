#include<stdio.h>
int main()
{
	int i,j,n,m;
	int a[10],A[10];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(j=0;j<m;j++)
		scanf("%d",&A[j]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){//printf("%d %d\n",a[i],A[j]); 
			if(a[i]==A[j])printf("%d ",a[i]);}
	return 0;
}
