#include<bits/stdc++.h>
using namespace std;

int const MAX = 2e5 + 5;

vector<int> nxt[MAX];//后节点
int depth[MAX];//深度
int vis[MAX];
int ans[MAX],num = 0;
int n,m;

priority_queue<int, vector<int>, greater<int> >Pq;//从小到大的优先队列

void topo() {
	for(int i = 1; i <= n; i++)
		if(depth[i] == 0 && !vis[i]) {
			Pq.push(i);
			vis[i] = 1;
		}
	while(!Pq.empty()) {
		int now = Pq.top();
		ans[num++] = now;
		Pq.pop();
		for(int j = 0; j < nxt[now].size(); j++) {
			depth[nxt[now][j]]--;
			if(depth[nxt[now][j]] == 0 && !vis[nxt[now][j]]) {
				Pq.push(nxt[now][j]);
				vis[nxt[now][j]] = 1;
			}

		}
	}

}
void __init() {
	for(int i = 0; i <= n; i++)
		nxt[i].clear();
	num = 0;
	memset(depth, 0, sizeof(depth));
	memset(vis, 0, sizeof(vis));
}
int main() {


	while(cin >> n >> m) {
		__init();
		int x , y;
		for(int i = 0; i < m; i++) {
			cin >> x >> y;
			nxt[x].push_back(y);
			depth[y] ++;
		}
		topo();
		for(int i = 0; i < n; i++) {
			cout << ans[i];
			if(i != n - 1)cout << " ";
		}
		cout << endl;
	}

}


