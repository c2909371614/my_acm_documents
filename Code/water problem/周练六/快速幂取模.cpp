#include<iostream>
#include<cstdio>
using namespace std;
long long pow4(long long a,long long b)
{
	long long ans;
	while(b){
		if(b&1) ans=(ans*a)%1000000007;
		a=a*a%1000000007;
		b>>=1;
	}
	return ans;
 } 
int main()
{
	int T;long long N;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&N);
		printf("%lld\n",pow4(N,N)); 
	}
	return 0;
}
