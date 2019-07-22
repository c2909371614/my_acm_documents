#include<stdio.h>
int main() 
{
	long long n,i,m,k,a[30000],b[30000];
	long long count=0;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=0;i<m;i++)
		b[i]=k;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		int j=0;
	for(i=n-1;i>=0;i--){
		
		if(b[j]-a[i]>=0){
			b[j]-=a[i];
			count++;
		} 
		else if(b[j]-a[i]<0){
			j++;
			if(j==m)break;
			b[j]-=a[i];
			count++;
				
		}	
	}
	printf("%lld",count);
	return 0;
}
