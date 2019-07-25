#include<bits/stdc++.h>
#define ll long long


const int MAX = 4e4 + 5;
using namespace std;
int n, m;

struct Node {
	int nxt,val;
	Node():nxt(-1),val(-1) {}
	Node(int x, int y):nxt(x),val(y) {}
};
vector<Node> node[MAX];

int  depth[MAX], F[MAX][30];
ll Dis[MAX];
void dfs(int x, int f) { //深度搜索赋值x节点到初始节点的距离Dis[x];
	//cout << "ok" << endl;
	F[x][0] = f;//2^0步祖先为父节点 
	for(int i = 0; i < node[x].size(); i++) {
		int nxt = node[x][i].nxt;
		if(nxt != f) { //不能反向
			depth[nxt] = depth[x] + 1;
			Dis[nxt] = Dis[x] + node[x][i].val;
			dfs(nxt, x);
		}
	}

}

void doubly() {
	for(int j = 1; j <= 25; j++) {
		for(int i = 1; i <= n; i++) {//树上倍增法 
			F[i][j] = F[F[i][j-1]][j-1];
		}
	}
}

int LCA(int x, int y) {
	if(depth[x] < depth[y]) { //wrap(x,y)保证x的深度大于y
		swap(x,y);
	}
	for(int i = 25; i >= 0; i--) { //x跳到尽可能近的点
		if((depth[x] - (1 << i)) >= depth[y])
			x = F[x][i];
	}
	if(x == y)//已经相等那就表明找到了
		return x;
	for(int i = 25; i >= 0; i--) {
		if(F[x][i] != F[y][i]) {
			x = F[x][i];
			y = F[y][i];

		}
	}
	return F[y][0];
}
void init() {
	for(int i = 0; i <= n; i++)
		node[i].clear();
	memset(F, 0, sizeof(F));
	for(int i = 0; i < MAX; i++)
		depth[i] = 1;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		init();
//		memset(depth, 1, sizeof(depth));
//		cout << " " << depth[0] << endl;
		cin >> n >> m;
		for(int i = 1; i < n; i++) {
			int x, y, z;
			cin >> x >> y >>z;
			node[x].push_back(Node(y,z));
			node[y].push_back(Node(x,z));
//			cout << "val:" << node[x][node[x].size()-1].val << endl;
		}
		dfs(1,1);
		doubly();
		
//		for(int i = 1; i <= n; i++)
//			cout << depth[i] << "-" << Dis[i] << " ";
//		cout<<endl;
		
		for(int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			cout << Dis[x] + Dis[y] - 2*Dis[LCA(x,y)] << endl;
//			cout << "lca:" << LCA(x,y) << endl;
		}
	}
}

