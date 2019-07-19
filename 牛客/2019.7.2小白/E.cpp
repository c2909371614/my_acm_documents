#include<bits/stdc++.h>
#define ll long long
//#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e3 + 5;
const ll INF = 0x3f3f3f3f;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7; 
int sum[9][9][1005];
int num[MAX];//Ͱ 
int a[9][9];
int n;
void dfs(int x, int y, int ans)
{
	if(x == n - 1 && y == n - 1){
		ans += a[n-1][n-1];
		num[ans]++;
		return;
	}
	if(x < n - 1)dfs(x+1, y, ans+a[x+1][y]);
	if(y < n - 1)dfs(x, y+1, ans+a[x][y+1]);
 } 
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
			
	int ans = 0;
	dfs(0,0,0);
	for(int i = 0; i < MAX; i++){
		if(num[i] != 0)
			ans++; 
	}
	cout << ans << endl;
}
