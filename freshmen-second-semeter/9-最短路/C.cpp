#include<bits/stdc++.h>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false);
using namespace std;
const int MAX = 1e6 + 5;
const ll INF = 0xffffff;
int n, m, s, End, tot;
/*vis用于访问标记， head储存head[x] x指向的最后一个输入的endpoint（存边）
edge储存边权nxt储存与该节点具有相同始点的编号*/
// head 与 nxt存的都是编号
int vis[MAX], head[MAX], nxt[MAX], ver[MAX], edge[MAX];
ll dis[MAX];//距离初始点的最小距离
queue<int> Q;//用于优化
void init() {
	memset(vis, 0, sizeof(vis));
	memset(nxt, 0, sizeof(nxt));
	memset(head, 0, sizeof(head));
	for(int i = 0; i <= 2*m; i++)
		edge[i] = INF, ver[i] = -1;

}
void add(int x, int y, int z) {
	ver[++tot] = y;
	edge[tot] = z;
	nxt[tot] = head[x];//没有的话就为 0
	head[x] = tot;//记录x的最后一个endpoint
}
void SFPA() {
	for(int i = 0; i <= 2*m; i++)
		dis[i] =  INF;//初始化为最大
	dis[s] = 0;//定义初始点
	Q.push(s);//推入队列
	vis[s] = 1; //入队标记
	while(!Q.empty()) {
		int x = Q.front();//当前访问的始点
		Q.pop();
		vis[x] = 0;//推出后取消标记
		for(int i = head[x]; i != 0; i = nxt[i]) { //查询所有对应的终点直到没有
			//i 为边的编号
			int y = ver[i];
			//cout << "dis:" << y << "-" << dis[y] << ">" << dis[x]+edge[i] << endl;  
			if(dis[y] > dis[x] + edge[i]) { //更新  松弛操作
				dis[y] = dis[x] + edge[i];
				if(!vis[y]) {
					Q.push(y);
					vis[y] = 1;
				}
			//	cout << x << "-" << dis[x] << endl;
			}
		}
	}
}
int main()
{
	FAST_IO; 
	cin >> n >> m >> s >> End;
	int x, y, z;
	init();
	for(int i = 1; i <= m; i++){
		cin >> x >> y >> z;
		add(x,y,z);
		add(y,x,z);
	}
	SFPA();
	cout << dis[End] << endl;
}
