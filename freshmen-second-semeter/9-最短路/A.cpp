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
	dis[from] = 0;//��from�ڵ㿪ʼ
	for(int i = 1; i < n; i++) { //����n-1��
		int x = 0;//���ڴ�����С������±�
		for(int j = 1; j <= n; j++)
			if(!vis[j] && (x == 0 || dis[x] > dis[j]))//v[j]û�����ڹ�����
				x = j;//�ҵ���С�ľ���
		vis[x] = 1;//���
		//cout << "min:" << from << "-" << x << " :" << dis[x] << endl;
		for(int j = 1; j <= n; j++) {
			dis[j] = min(dis[j], dis[x] + edge[x][j]);//����С��ȥ����������·��
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
	init();//��ʼ�� 
	for(int i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		edge[x][y] = min(edge[x][y], z);
		edge[y][x] = min(edge[y][x], z);//���ر߼��� 
	}
	dijkstra();
	cout << dis[to] << endl; 
}

