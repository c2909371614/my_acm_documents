
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 2e5+5;
int a[MAX]/*, tree[4*MAX]*/;
int id = 0;
int n, m;//组数 , ask
struct Tree {
	int sum;
	int Max;
	int Min;
	Tree():sum(0),Max(-INF),Min(INF) {} //初始化
	_init(){
		Tree();
	}
} tree[4*MAX];
void Build(int L, int R, int node) { //tree - node
	if(L == R) {
		tree[node].sum = a[++id];//从头开始
		tree[node].Max = a[id];
//		tree[node].Min = min(tree[node].Min, a[id]);
		return;
	}
	int mid   = (L + R) >> 1;
	int left  = node * 2 + 1;
	int right = node * 2 + 2;
	Build(L,     mid,  left);
	Build(mid + 1, R, right);
//	tree[node].sum = tree[left].sum + tree[right].sum;
	tree[node].Max = max(tree[left].Max, tree[right].Max);
//	tree[node].Min = min(tree[left].Min, tree[right].Min); //更新
}
//void add(int id, int node, int L, int R, int val) { //id为改变的下标，val为改变的值 node为数的下标
//	if(L == R) {
//		tree[node].sum += val;
//		return;
//	}
//	int mid   = (L + R) >> 1;
//	int left  = node * 2 + 1;
//	int right = node * 2 + 2;
//	if(id <= mid)
//		add(id, left, L, mid, val);
//	else
//		add(id, right, mid + 1, R, val);
//	tree[node].sum = tree[left].sum + tree[right].sum;
//}

//将数组a[id]改成a[update] 全部更新
void change(int id, int node, int L, int R, int update) {
	if(L == R) {
		tree[node].sum = update;//更新
		tree[node].Max = update;
//		tree[node].Min = update;
		return;
	}
	int mid   = (L + R) >> 1;
	int left  = node * 2 + 1;
	int right = node * 2 + 2;
	if(id <= mid)
		change(id, left, L, mid, update);
	else
		change(id, right, mid + 1, R, update);
//	tree[node].sum = tree[left].sum + tree[right].sum;
	tree[node].Max = max(tree[left].Max, tree[right].Max);
//	tree[node].Min = min(tree[left].Min, tree[right].Min); //更新
}

Tree Find(int x, int y, int L, int R, int node) {
	Tree ans;
//	if(x > R || y < L) {
//		return ans;
//	}
	if(x <= L && y >= R) {//在区间中 
//		ans.sum = tree[node].sum;
		ans.Max = tree[node].Max;
//		ans.Min = tree[node].Min; //更新
		return ans;
	}
	int mid   = (L + R) >> 1;
	int left  = node * 2 + 1;
	int right = node * 2 + 2;
	if(x <= mid) {
		ans.Max = max(ans.Max, Find(x, y, L    , mid, left).Max);
//		ans.Min = min(ans.Min, Find(x, y, L, mid, left).Min); //更新
//		ans.sum += Find(x, y, L, mid, left).sum;
	}

	if(y > mid) {
		ans.Max = max(ans.Max, Find(x, y, mid + 1, R, right).Max);
//		ans.Min = min(ans.Min, Find(x, y, mid + 1, R, right).Min); //更新
//		ans.sum += Find(x, y, L, mid, right).sum;
	}
//	ans += sum(x, y, mid + 1, R, right);
	return ans;
}
int pos_i = 0;
void display(int L, int R, int node) {
	printf("%d-%d:%d\n", L, R, tree[node].Max);
	if(L == R) {

		printf("tree[%d]=%d", ++pos_i, tree[node].sum);
		pos_i % 1 == 0 && pos_i?printf("\n"):1;
		return;
	}
	int mid   = (L + R) >> 1;
	int left  = node * 2 + 1;
	int right = node * 2 + 2;
	display(L, mid, left);
	display(mid + 1, R, right);
}
void init() {
	id = 0;//初始化 
	for(int i = 0; i <= 4 * n; i++)
		tree[i]._init();
}

fstream In("data.in",ios::in);//读取
fstream Out("my_data.out",ios::out);//写入#include<iostream>

int main() {
//	scanf("%d%d", &n, &m);
	In >> n >> m;
	init();
	for(int i = 1; i <= n; i++)
//		scanf("%d", &a[i]);
		In >> a[i];
	getchar();//消除回车 
	Build(1, n, 0);//建立 
	char ask;
	for(int i = 0; i < m; i++) {
		int x, y;
//		scanf("%c%d%d", &ask, &x, &y);
		In >> ask >> x >> y;
		getchar();
//		printf("ask=%c x=%d y=%d \n", ask, x, y); 
		if(ask == 'Q'){

//			printf("%d\n", Find(x, y, 1, n, 0).Max);
			Out << Find(x, y, 1, n, 0).Max << endl;
		}
			
		else if(ask == 'U')
			change(x, 0, 1, n, y);
//		pos_i = 0;
//		display(1, n, 0);
	}
	In.close();
	Out.close();
	return 0;
}
