#include<bits/stdc++.h>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false);

const ll MOD = 1000000007;
using namespace std;

const ll MAX = 2e5 + 5;

struct Num {
	ll x,y;
} num[MAX];

bool cmp(Num a, Num b) {
	return a.y*b.x > b.y*a.x;
}

ll quick(ll a,ll b) {
	ll s = 1;
	while (b > 0) {
		if (b % 2 == 1) {//b=b>>1保证了在最后一步肯定会执行该if判断
			s = s * a%MOD;
		}
		a = (a * a)%MOD;
		b = b >> 1;
	}
	return s;
}

ll get_inv(ll a,ll b,ll c) {
	return (a * quick(b, c - 2)) % c;
}
int main() {
	//cout << " " << quick(2,5) << endl;
	cout << get_inv(1,12,1e9+7)<<endl;
//	ll n;
//	cin >> n;
//	for(ll i = 0; i < n; i++)
//	{
//		cin >> num[i].x >> num[i].y;
//	 }
//	sort(num, num + n,cmp);
//	for(ll i = 0; i < n; i++){
//		cout << get_inv(num[i].y, num[i].x, MOD)<< endl;
//	}
	return 0;
}
