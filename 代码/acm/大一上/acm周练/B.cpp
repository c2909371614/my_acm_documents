#include <iostream>
using namespace std;
#define ll long long
const int MOD = 1000000007;
ll quick_power(ll a,ll b,ll c)
{
    ll ans=1;
    a=a%c;
    while(b!=0)
    {
        if(b&1)
            ans=(ans*a)%c;
        b>>=1;
        a=(a*a)%c;
    }
    return ans;
}

int main()
{
	ll n;
	while(cin>>n){
		cout<<quick_power(2,n*n-1,MOD)<<endl;
	}
	return 0;
}
