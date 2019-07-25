#include<bits/stdc++.h>
#define ll long long
const int MAX=1e5+5;
using namespace std;
ll pow_mod(ll a,ll n,ll m) { //a^b%m
	if(n==0)
		return 1;
	ll x=pow_mod(a,n/2,m);
	ll ans=x*x%m;
	if(n&1)
		ans=ans*a%m;
	return ans;
}

int main() 
{
	loop();
}
