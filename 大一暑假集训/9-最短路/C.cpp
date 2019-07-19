#include<bits/stdc++.h>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false);
using namespace std;
const int MAX = 1e6 + 5;
const ll INF = 0xffffff;
int n, m, s, End, tot;
/*vis���ڷ��ʱ�ǣ� head����head[x] xָ������һ�������endpoint����ߣ�
edge�����Ȩnxt������ýڵ������ͬʼ��ı��*/
// head �� nxt��Ķ��Ǳ��
int vis[MAX], head[MAX], nxt[MAX], ver[MAX], edge[MAX];
ll dis[MAX];//�����ʼ�����С����
queue<int> Q;//�����Ż�
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
	nxt[tot] = head[x];//û�еĻ���Ϊ 0
	head[x] = tot;//��¼x�����һ��endpoint
}
void SFPA() {
	for(int i = 0; i <= 2*m; i++)
		dis[i] =  INF;//��ʼ��Ϊ���
	dis[s] = 0;//�����ʼ��
	Q.push(s);//�������
	vis[s] = 1; //��ӱ��
	while(!Q.empty()) {
		int x = Q.front();//��ǰ���ʵ�ʼ��
		Q.pop();
		vis[x] = 0;//�Ƴ���ȡ�����
		for(int i = head[x]; i != 0; i = nxt[i]) { //��ѯ���ж�Ӧ���յ�ֱ��û��
			//i Ϊ�ߵı��
			int y = ver[i];
			//cout << "dis:" << y << "-" << dis[y] << ">" << dis[x]+edge[i] << endl;  
			if(dis[y] > dis[x] + edge[i]) { //����  �ɳڲ���
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
