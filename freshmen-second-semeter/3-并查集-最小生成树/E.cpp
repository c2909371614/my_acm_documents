#include<bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(false)
using namespace std;

int const MAX = 5e5 + 5;

vector<int> nxt[MAX];//后节点

struct Edge {
	int x, y, z;
	Edge():x(-1), y(-1) {}
} edge[MAX];
int F[MAX], n, m, ans = 0;

bool cmp(Edge a, Edge b) {
	return a.z < b.z;
}
int find(int x) {
	if(x == F[x])return x;
	return F[x] = find(F[x]);
}
int main() {
	cin >> n >> m;
	while(n != 0) {
		ans = 0;
		for(int i = 1; i <= n; i++) {
			cin >> edge[i].x >> edge[i].y >> edge[i].z ;
		}
		sort(edge + 1, edge + n + 1, cmp);
		for(int i = 0; i <= m; i++)//m个点 
			F[i] = i;
		int num = 1 ;
		for(int i = 1; num < m && i <= n; i++) {
			int x = find(edge[i].x);
			int y = find(edge[i].y);
			if(x != y) {
				F[x] = y;//x合并到y
				ans += edge[i].z;
				//cout << ans <<endl;
				num++;
			}
			
		}
	//	cout<<" "<<num<<endl;
		
		int flag = true;//是否畅通 
		int root = find(1);
		for(int i = 1; i <= m; i++) {
		//	cout << find(i) <<endl;
			if(find(i) != root) flag = false;
		}
		if(flag)cout << ans <<endl;
		else cout<< "?" /*<< ans */<< endl;
		cin >> n >> m;
	}
}
