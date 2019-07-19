#include<bits/stdc++.h>
#define ll long long
//#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e3 + 5;
const ll INF = 0x3f3f3f3f;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7; 
int n, m;
ll sum[MAX];
int main()
{
	//cout << MOD <<endl;
	cin >> n >> m;
	sum[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		sum[i] = (sum[i-1] * 2 + 2) % MOD;
		//printf("sum[%lld] = %d\n", i, sum[i]);
	}
	while(m--)
	{
		int x, y;
		cin >> x >> y;
		ll ans = 0;
		for(int i = x; i <= y; i++)
		{
			ans += sum[i]%MOD;
			ans = ans%MOD;
		} 
		 cout << ans << endl;
	 } 
	return 0;
}
