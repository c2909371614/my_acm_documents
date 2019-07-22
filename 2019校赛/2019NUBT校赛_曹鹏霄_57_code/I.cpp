#include<bits/stdc++.h>
#define ll long long
const int MAX=1e5+5;
using namespace std;

int main()
{
	ll T,a[MAX];
	ll x,y,z;
	ll sum;
	ll n,m,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<m;i++)
		{
			
			scanf("%lld%lld%lld",&x,&y,&z);
			if(x==1){
				for(j=y-1;j<=z-1;j++){
					a[j]+=j+1-y+1;
				}
			}
			else{
				sum=0;
				for(j=y-1;j<=z-1;j++){
					sum+=a[j];
				}
				printf("%lld\n",sum);
			}
				
		}
	}
}
