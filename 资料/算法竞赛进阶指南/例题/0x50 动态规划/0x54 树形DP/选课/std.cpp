#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> son[310];
int f[310][310], s[310], n, m;

void dp(int x) {
	f[x][0] = 0;
	for (int i = 0; i < son[x].size(); i++) { // 循环子节点（物品）
		int y = son[x][i];
		dp(y);
		for (int t = m; t >= 0; t--) // 倒序循环当前选课总门数（当前背包体积）
			for (int j = t; j >= 0; j--) // 循环更深子树上的选课门数（组内物品）
				if (t - j >= 0)
                    f[x][t] = max(f[x][t], f[x][t-j] + f[y][j]);
	}
	if (x != 0) // x不为0时，选修x本身需要占用1门课，并获得相应学分
		for(int t = m; t > 0; t--)
			f[x][t] = f[x][t-1] + s[x];
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x >> s[i];
		son[x].push_back(i);
		
	}
	memset(f, 0xcf, sizeof(f)); // -INF
	dp(0);
	cout << f[0][m] << endl;
}