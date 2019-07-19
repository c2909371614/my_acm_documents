#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 5e5+5;
int a[MAX], tree[4*MAX];
int id = 0;
void Build(int L, int R, int node) { //tree - node
	if(L == R) {
		tree[node] = a[++id];//从头开始
		return;
	}
	int mid   = (L + R) >> 1;
	int left  = node * 2 + 1;
	int right = node * 2 + 2;
	Build(L, mid, left);
	Build(mid + 1, R, right);
	tree[node] = tree[left] + tree[right];
}
void add(int id, int node, int L, int R, int val) { //id为改变的下标，val为改变的值 node为数的下标
	if(L == R) {
		tree[node] += val;
		return;
	}
	int mid   = (L + R) >> 1;
	int left  = node * 2 + 1;
	int right = node * 2 + 2;
	if(id <= mid)
		add(id, left, L, mid, val);
	else
		add(id, right, mid + 1, R, val);
	tree[node] = tree[left] + tree[right];
}
int sum(int x, int y, int L, int R, int node) {
	//printf("OK");
	if(x > R || y < L) {
		return 0;
	}
//	if(L == R) {
//		return tree[node];
//	}
	if(x <= L && y >= R) {
		return tree[node];
	}
	int mid   = (L + R) >> 1;
	int left  = node * 2 + 1;
	int right = node * 2 + 2;
	int ans = 0;
	
	if(x <= mid)
		ans += sum(x, y, L, mid, left);
	if(y > mid)
		ans += sum(x, y, mid + 1, R, right);
	return ans;
}
int pos_i = 0;
void display(int L, int R, int node)
{
	//printf("%d=%d- ",L,R); 
	if(L == R) {
		
		printf("tree[%d]=%d ", ++pos_i, tree[node]);
		pos_i % 3 == 0 && pos_i?printf("\n"):1;
		return;
	}
	int mid   = (L + R) >> 1;
	int left  = node * 2 + 1;
	int right = node * 2 + 2;
	display(L, mid, left);
	display(mid + 1, R, right);
}
void init()
{
	memset(tree, 0, sizeof(tree));
	id = 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	int temp = t;
	while(t--)
	{
		init();  
		int n;
		scanf("%d", &n);
		getchar();
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		Build(1, n, 0);//从0开始建树 区间为1-n
//		display(1, n, 0); 
		char ask[20];
		scanf("%s", ask);//cout<<"ok";
//		ask =="\n"? printf("hehehe"):1;
		printf("Case %d:\n",temp - t);
		while((string)ask != "End")
		{
			int x, y;
			//cout<<ask<<" ask"<<endl;
			scanf("%d%d",&x,&y);
			//printf("x-y:%d-%d\n",x,y); 
			if(!strcmp(ask, "Query")){
				printf("%d\n",sum(x, y, 1, n, 0));
			}	
			else if(!strcmp(ask, "Add")){
//				cout<<"add"<<endl;
				add(x, 0, 1, n, y);//x为a【x】中的x
			}
				
			else if(!strcmp(ask, "Sub"))
				add(x, 0, 1, n, -y);//减去 
			scanf("%s", ask);
//			pos_i=0;
//			display(1,n,0);
		}
	}
}
