#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e3 + 5;
int n;
int dp[MAX][MAX];
int sum[MAX];
int a[MAX];
int main()
{
	FAST_IO;
	cin >> n;
	/*memset 是按字节进行赋值，能将数组整个初始化为 
	3f3f3f3f3f3f3f3f3f3f3f3f3f...... ，也就是无穷大了*/
	memset(dp, 0x3f, sizeof(dp));
//	cout << 0x3f << endl;
//	cout << dp[20][20] << endl;
	for(int i = 1; i <= n; i++)
	{
		dp[i][i] = 0;
		cin >> a[i];
		sum[i] = sum[i-1] + a[i]; 
	}
	for(int len = 2; len <= n; len++)
		for(int l = 1; l <= n - len + 1; l++){
			int r = l + len - 1;
			for(int k = l; k <= r; k++)
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
			dp[l][r] += sum[r] - sum[l-1];//包含a[l] 
		} 
	cout << dp[1][n] << endl; 
}
