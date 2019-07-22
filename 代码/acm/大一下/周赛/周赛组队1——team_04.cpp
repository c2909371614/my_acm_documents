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
int main(){
	int T;
	ll ans ,s;
	cin>>T;
	while (T--){
		cin>>s;
		cout<<(quick_power(2,s-1,1000000007)%1000000007*3)%1000000007<<endl;
	}
} 
