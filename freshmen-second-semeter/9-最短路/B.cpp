#include<bits/stdc++.h>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false);
using namespace std;
const int MAX = 1e3 + 5;
const int INF = 0xfffffff;
int dis[MAX][MAX];//i--j
int n, m, from, to;
void init() {
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			dis[i][j] = INF;
}
int main() {
	cin >> n >> m >> from >> to;
	init();
	int x, y, z;
	for(int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		dis[x][y] = min(dis[x][y], z);//对多重边进行兼容
		dis[y][x] = min(dis[y][x], z);
	}
	for(int i = 0; i <= n; i++)
		dis[i][i] = 0;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		for(int j = 1; j <= n; j++)
			cout << dis[i][j] << " ";
		cout << endl;
	}
		 
}
