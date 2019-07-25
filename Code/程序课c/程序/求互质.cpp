#include<stdio.h>
#include<math.h> 
int main() 
{
	
	int n,m,i,j,bug=0;
    int a[100];
	int k[100];
	scanf("%d%d",&n,&m);
    
	for(i=2;i<=sqrt(n);i++)
	    
	    if(n%i==0)a[i]=i;
	for(j=2;j<=sqrt(m);j++)
	    if(m%i==0)k[j]=j;
	for(i=2;i<=sqrt(n);i++)
	    for(j=2;j<=sqrt(m);j++)
	        if(a[i]==k[j])bug++;
	if(bug==0)printf("yes");
	else printf("no");
	return 0;
}
