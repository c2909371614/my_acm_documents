#include<bits/stdc++.h>
using namespace std;

int const MAX = 5e5 + 5;

vector<int> nxt[MAX];//后节点

#define FAST_IO ios::sync_with_stdio(false)

int p[MAX]; 
int r[MAX];//深度 
int num[MAX];
int index[MAX];
//initial the sets
void init(){
    for(int i = 0; i < MAX; i++){
        p[i] = i;
    }
}
//Find(x) return the root of x
int Find(int x){
    if(x == p[x]) return x;
    else return p[x] = Find(p[x]);//路径压缩，p直接赋值给root 
}

//Union(x, y) union the sets of x and y
void Union(int x, int y){
    int xRoot = Find(x);
    int yRoot = Find(y);

    if(xRoot == yRoot) return;
    if(r[xRoot] < r[yRoot]) p[xRoot] = yRoot;
    else if(r[xRoot] > r[yRoot]) p[yRoot] = xRoot;
    else{
        p[yRoot] = xRoot;
        r[xRoot]++;
    }
}

bool sameRoot(int x, int y){
    return Find(x) == Find(y);
}

int main()
{
	int n, m;
	cin >> n >> m;
	init();
	for(int i = 0; i < m ; i++)
	{
		int t;
		cin >> t;
		int a[t];
		for(int j = 0; j < t; j++)
		{
			 cin >> a[j];
			 if(j)Union(a[j-1], a[j]);
		 } 
	 }
	for(int i = 1; i <= n; i++)
	{
		index[i] = Find(i);
		num[index[i]]++;
	//	cout<<i<<"-"<<index[i]<<" ";
	 } 
	for(int i = 1; i <= n; i++){
		cout << num[Find(i)];
		if(i != n)cout << " "; 
	}
}
