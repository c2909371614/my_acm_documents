#include<bits/stdc++.h>
#define ll long long
#define N 10010
#define FAST_IO ios::sync_with_stdio(false)
using namespace std;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double pi = acos(-1);
fstream In("data.in",ios::in);//∂¡»°
fstream Out("my_data.out",ios::out);//–¥»Î 
ll j_pow(ll m, ll n, ll a1)
{
	ll ans = 1;
	while(a1)
	{
		if(a1 % 2 == 1)
			ans = ans * m % n;
		m = (m * m) % n;
		a1 /= 2;
	}
	return ans%n ;
}  
int main() {
//	cout << j_pow(2, 3, 2) << " pi=" << pi << endl;   
    ll m, n, a1, a2;
    ll T;
    In>>T;
    while (T--) {
        In>>m>>n>>a1>>a2;
		m = m%n*j_pow(10, n, a1 - 1 )%n; 
        for (ll i = a1; i <= a2; i++) {
            Out<<m*10LL/n;
            m = m * 10LL % n;
        }
        Out << endl;
    }
}
