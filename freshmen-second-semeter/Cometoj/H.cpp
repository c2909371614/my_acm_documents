#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll a[MAX];
bool cmp(ll a, ll b){
	return a < b;
}
int main()
{
	ll n;
	cin >> n;
	ll ans = 1;
	ll sum = 1;
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	ll count = 1;
	sort(a, a+n, cmp);
	ll temp;
	ll flag =  0;
	for(ll i = 1; i < n; i++){
		if(a[i] == a[i-1])
			ans *= count + 1,
			flag = a[i],
			count++;
		else if(count + flag - a[i] + 1 > 0) 
			ans *= count + flag - a[i] + 1,
			count++;
		else {
			sum *= ans;
			sum %= MOD; 
			temp = ans;
			ans = 1;
			count = 1;
		}
		ans %= MOD; 
//		cout << " " << sum << endl;
	}
	sum *= ans;
	cout << sum%MOD << endl;
 } 
