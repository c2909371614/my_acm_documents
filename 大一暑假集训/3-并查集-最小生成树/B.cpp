#include<bits/stdc++.h>
using namespace std;

int const MAX = 5e5 + 5;

vector<int> nxt[MAX];//后节点

struct Edge {
	int x, y;
	Edge():x(-1), y(-1) {}
} edge[MAX];
#define FAST_IO ios::sync_with_stdio(false)

int p[MAX];
int r[MAX];
int num[MAX];
int index[MAX];
//initial the sets
void init() {
	for(int i = 0; i < MAX; i++) {
		p[i] = i;
	}
}
//Find(x) return the root of x
int Find(int x) {
	if(x == p[x]) return x;
	else return p[x] = Find(p[x]);//路径压缩，p直接赋值给root
}

//Union(x, y) union the sets of x and y
void Union(int x, int y) {
	int xRoot = Find(x);
	int yRoot = Find(y);

	if(xRoot == yRoot) return;
	if(r[xRoot] < r[yRoot]) p[xRoot] = yRoot;
	else if(r[xRoot] > r[yRoot]) p[yRoot] = xRoot;
	else {
		p[yRoot] = xRoot;
		r[xRoot]++;
	}
}

bool sameRoot(int x, int y) {
	//printf("root of %d: %d\n", x, Find(x));
	//printf("root of %d: %d\n", y, Find(y));
	return Find(x) == Find(y);
}
int main() {
	FAST_IO;
	int n, m;
	while(cin >> n >> m) {
		init();
		for(int i = 0; i < m ; i++) {
			int x, y;
			cin >> x >> y;
			edge[i].x = x;
			edge[i].y = y;
		}
		int Num = n;
		for(int i = m - 1; i >= 0; i--) {
			num[i] = Num;
			if(Find(edge[i].x) != Find(edge[i].y)) {
				Union(edge[i].x, edge[i].y);
				Num--;
			}
		}
		for(int i = 0; i < m; i++) {
			cout << num[i];
			cout << endl;
		}
	}

}
