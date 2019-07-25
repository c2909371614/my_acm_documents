#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define LL long long
const int N = 5e4 + 5;
int n, m, tot, na, nb;//tot为节点编号  
int h[N], ne[N<<1], to[N<<1];//h记录以x节点为始点的最后输入的边的编号 
							//ne[i]用于记录与边i有着同一个始点的上一条边的编号 
LL w[N<<1];                  //to[i]为边i的终点 
int f[N][18], army[N];//f[i][j]记录着从节点i到节点j的边的编号 
LL dis[N][18];// 
void add(int x,int y,int z) {
	to[++tot] = y, ne[tot] = h[x], h[x] = tot, w[tot] = z;
}
void dfs(int x, int las, LL havego) { //1.预处理倍增
	f[x][0] = las, dis[x][0] = havego;
	for(int i = 1; i <= 17; ++i) {//最多跑17? 
		f[x][i]   = f[f[x][i-1]][i-1];
		dis[x][i] = dis[x][i-1] + dis[f[x][i-1]][i-1];
	}
	for(int i = h[x]; i != -1; i = ne[i])
		if(to[i] != las) dfs(to[i], x, w[i]);
}
//以上代码得到dis[i][j]，节点i到j的距离 
struct node {
	LL rest;
	int id;
} a[N],b[N];
//vis标记是否被封死 
int vis[N], used[N], restbj[N];
LL restmin[N];
int checkok(int x, int las) { //5.dfs找未被“封死”的子树
	int bj = 1, i, bbj = 0;
	if(vis[x])return 1;//封死直接返回 1 
	for(i = h[x]; i != -1; i = ne[i]) {
		if(to[i]==las)continue;
		bbj=1;
		if(!checkok(to[i],x)) {
			bj=0;
			if(x==1) b[++nb].id=to[i],b[nb].rest=w[i];
			else return 0;
		}
	}
	if(!bbj)return 0;
	return bj;
}
bool cmp(node x, node y) {
	return x.rest > y.rest;
}
int check(LL lim) {
	int i, j, x, now;
	LL num;
	na = nb = 0;
	for(i = 1; i <= n; ++i)
		vis[i] = restbj[i] = 0;//初始化封死信息 
	for(i = 1; i <= m; ++i)
		used[i] = 0;
	for(i = 1; i <= m; ++i) {
		x = army[i], num = 0;
		for(j = 17; j >= 0; --j) //3.上提军队
			if(f[x][j] > 1 && num + dis[x][j] <= lim)
				num += dis[x][j],
				x = f[x][j];
		if(f[x][0] == 1 && num + dis[x][0] <= lim) { //4.处理剩余路程
			a[++na].rest = lim - num - dis[x][0],
			a[na].id = i;
			if(!restbj[x] || a[na].rest < restmin[x])
				restmin[x] = a[na].rest, 
				restbj[x] = i;
		} else vis[x] = 1;
	}
	if(checkok(1, 0))
		return 1;
	sort(a+1, a+1+na, cmp);
	sort(b+1, b+1+nb, cmp);//6.军队在子树间转移
	now = 1;
	used[0] = 1;
	for(i = 1; i <= nb; ++i) {
		if(!used[restbj[b[i].id]]) {
			used[restbj[b[i].id]] = 1;
			continue;
		}
		while(now <= na&&(used[a[now].id] || a[now].rest < b[i].rest))++now;
		if(now > na)return 0;
		used[a[now].id] = 1;
	}
	return 1;
}
int main() {
	int i, x, y, z;
	LL l = 0, r = 5e5, mid, ans = -1;
	cin >> n; 
	for(i = 1; i <= n; ++i)h[i] = -1;//初始化h数组为-1 
	for(i=1; i<n; ++i) {
		cin >> x >> y >> z;//输入 
		add(x,y,z), add(y,x,z);//加边 
	}
	dfs(1, 0, 0);//寻找未被封死的子树 
	cin >> m; 
	for(i = 1; i <= m; ++i)army[i] = read();
	while(l <= r) { //2.二分答案
		mid = (l + r) >> 1;
		if(check(mid))r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	printf("%lld", ans);
	return 0;
}
