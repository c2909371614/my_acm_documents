#include <iostream>
using namespace std;
#define ll long long
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
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<quick_power(n,n,10)<<endl;
	}
	return 0;
}
