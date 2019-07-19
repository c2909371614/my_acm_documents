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
const int MAX = 5e4+5;
int a[MAX]/*, tree[4*MAX]*/;
int id = 0;
int n, m;//组数 , ask
int my_count = 0;
struct SegTree {
	int dis_i;
	int a[MAX];
	struct Tree {
		int L, R;
		int sum;
		int Max;
		int Min;
		int Lazy; 
		Tree():sum(0),Max(-INF),Min(INF),Lazy(0),L(-1),R(-1) {} //初始化
		void my_Init() {
			Tree();
		}
		void update(int val){
			sum  += val * (R - L + 1);
			Lazy += val;
			Max  += val;
			Min  += val;
		}
	} tree[4*MAX];
	void push_up(int node){//向上更新 
		int left  = node * 2 + 1;
		int right = node * 2 + 2; 
		tree[node].sum = tree[left].sum + tree[right].sum;
		tree[node].Max = max(tree[left].Max, tree[right].Max);
		tree[node].Min = min(tree[left].Min, tree[right].Min);
	}
	void push_down(int node){//向下更新 
		if(tree[node].Lazy == 0)return;
		tree[node * 2 + 1].update(tree[node].Lazy);
		tree[node * 2 + 2].update(tree[node].Lazy);
		tree[node].Lazy = 0;//标记清零 
	}
	void Build(int L, int R, int node) { //tree - node
		tree[node].L = L;
		tree[node].R = R; 
		if(L == R) {
			tree[node].sum = a[++id];//从头开始
			tree[node].Max = a[id];
			tree[node].Min = a[id];
			return;
		}
		int mid   = (L + R) >> 1;
		int left  = node * 2 + 1;
		int right = node * 2 + 2;
		Build(L,     mid,  left);
		Build(mid + 1, R, right);
		push_up(node) //向上更新
	}
//区间加
	void Area_add(int x, int y, int node, int val) { //id为改变的下标，val为改变的值 node为数的下标
		if(x <= tree[node].R && tree[node].L >= y) {
			tree[node].update(val);
			return;
		}
		push_down(node);//向下更新 
		int mid   = (tree[node].L + tree[node].L) >> 1;
		int left  = node * 2 + 1;
		int right = node * 2 + 2;
		if(x <= mid)
			Area_add(x, y, left , val);
		else
			Area_add(x, y, right, val);
		push_up(node);//向上更新 
	}

//将数组a[id]改成a[update] 全部更新
//void change(int id, int node, int L, int R, int update) {
//	if(L == R) {
//		tree[node].sum = update;//更新
//		tree[node].Max = update;
//		tree[node].Min = update;
//		return;
//	}
//	int mid   = (L + R) >> 1;
//	int left  = node * 2 + 1;
//	int right = node * 2 + 2;
//	if(id <= mid)
//		change(id, left, L, mid, update);
//	else
//		change(id, right, mid + 1, R, update);
////	tree[node].sum = tree[left].sum + tree[right].sum;
//	tree[node].Max = max(tree[left].Max, tree[right].Max);
//	tree[node].Min = min(tree[left].Min, tree[right].Min); //更新
//}
	int Find_sum(int x, int y, int node) {
		int ans = 0;
		if(x <= tree[node].L && y >= tree[node].R) {//在区间中
			ans = tree[node].sum;
			return ans;
		}
		push_down(node); 
		int mid   = (tree[node].L + tree[node].L) >> 1;
		int left  = node * 2 + 1;
		int right = node * 2 + 2;
		if(x <= mid) {//更新
			ans.sum += Find(x, y, left).sum;
		}
		if(y > mid) {
			ans.sum += Find(x, y, left).sum;
		}
		push_up(node);
		return ans;
	}
//	int Find_Max(int x, int y, int L, int R, int node) {
//		int ans = -INF;
//		if(x <= L && y >= R) {//在区间中
////		ans.sum = tree[node].sum;
//			ans = tree[node].Max;
//			return ans;
//		}
//		int mid   = (L + R) >> 1;
//		int left  = node * 2 + 1;
//		int right = node * 2 + 2;
//		if(x <= mid) {
//			ans = max(ans, Find_Max(x, y, L, mid, left));
//		}
//		if(y > mid) {
//			ans = max(ans, Find_Max(x, y, mid + 1, R, right));
//		}
//		return ans;
//	}
//	int Find_Min(int x, int y, int L, int R, int node) {
//		int ans = INF;
//		if(x <= L && y >= R) {//在区间中
//			ans = tree[node].Min;
//			return ans;
//		}
//		int mid   = (L + R) >> 1;
//		int left  = node * 2 + 1;
//		int right = node * 2 + 2;
//		if(x <= mid) {
//			ans = min(ans, Find_Min(x, y, L, mid, left)); //更新
////		ans.sum += Find(x, y, L, mid, left).sum;
//		}
//		if(y > mid) {
//			ans = min(ans, Find_Min(x, y, mid + 1, R, right));
//		}
////	ans += sum(x, y, mid + 1, R, right);
//		return ans;
//	}
//	void display(int L, int R, int node) {
//		printf("%d-%d:%d\n", L, R, tree[node].Max);
//		if(L == R) {
//
//			printf("tree[%d]=%d", ++dis_i, tree[node].sum);
//			dis_i % 1 == 0 && dis_i?printf("\n"):1;
//			return;
//		}
//		int mid   = (L + R) >> 1;
//		int left  = node * 2 + 1;
//		int right = node * 2 + 2;
//		display(L, mid, left);
//		display(mid + 1, R, right);
//	}
//	void init() {
//		id = 0;//初始化
//		for(int i = 0; i <= 4 * n; i++)
//			tree[i].my_Init();
//	}
};

int main() {
	scanf("%d%d", &n, &m);
	//init();
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int x, y;
	Build(1, n, 0);
	for(int i = 0; i < m; i++) {
//		my_count = 0;
		scanf("%d%d", &x, &y);
		int Max = Find_Max(x, y, 1, n, 0);
		int Min = Find_Min(x, y, 1, n, 0);
		printf("%d\n",Max - Min);
	}
	return 0;
}
