#include<bits/stdc++.h>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false);
using namespace std;
const int MAX = 1e5 + 5;
const int INF = 0xfffffff;
int edge[MAX][MAX];//i--j
int vis[MAX];
int dis[MAX];
int n, m, from, to;
void dijkstra() {
	for(int i = 0; i <= n; i++)
		dis[i] = INF;
	memset(vis, 0, sizeof(vis));
	dis[from] = 0;//从from节点开始
	for(int i = 1; i < n; i++) { //更新n-1次
		int x = 0;//用于储存最小距离的下标
		for(int j = 1; j <= n; j++)
			if(!vis[j] && (x == 0 || dis[x] > dis[j]))//v[j]没有用于过更新
				x = j;//找到最小的距离
		vis[x] = 1;//标记
		//cout << "min:" << from << "-" << x << " :" << dis[x] << endl;
		for(int j = 1; j <= n; j++) {
			dis[j] = min(dis[j], dis[x] + edge[x][j]);//用最小边去更新其他的路径
		}
	}
}
void init() {
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++) {
			edge[i][j] = INF;
		}
}
int main() {
	cin >> n >> m >> from >> to;
	int x, y, z;
	init();//初始化 
	for(int i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		edge[x][y] = min(edge[x][y], z);
		edge[y][x] = min(edge[y][x], z);//多重边兼容 
	}
	dijkstra();
	cout << dis[to] << endl; 
}

