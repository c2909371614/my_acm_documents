#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 2e2+5;
int n;
int dp[MAX][MAX];
int a[MAX], b[MAX];
int main() {
	int t;
	cin >> t;
	int temp = t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
			for(int j = i; j<= n; j++)
				dp[i][j] = INF;
		for(int len = 1; len <= n; len++)
			for(int l = 1; l <= n - len + 1; l++) {
				int r = l + len - 1;
				for(int k = l; k <= r; k++) { //推导前提dp[l][k-1]dp[k+1][r]已经推导出来
					dp[l][r] = min(dp[l][r], dp[l][k-1] + a[k] + dp[k+1][r] + b[r+1] + b[l-1]);
				}
			}
			cout << "Case #" << temp - t << ": " << dp[1][n] << endl;
	}
}
