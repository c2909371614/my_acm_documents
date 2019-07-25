#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdio>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e5+5;
const int INF = 0x3f3f3f3f;
int f[MAX];
int num[MAX];//num��¼���ڳ�Ա����
int n, m;
int Find(int x) {
	if(f[x] == x)return x;
	return f[x] = Find(f[x]);//·��ѹ��
}
void Union(int x, int y) { //y�ӵ�x
	int xx = Find(x);
	int yy = Find(y);
	if(xx == yy)return ;
	else {
		num[xx] += num[yy];
		num[yy] = 0;
		f[yy] = xx;
	}  
}
void init() {
	for(int i = 0; i <= n; i++)
		f[i] = i, num[i] = 1;
}
int main() {
//	FAST_IO;
//	cin >> n >> m;
	scanf("%d%d",&n,&m);
	int a[MAX], b[MAX];
	ll ans[MAX];
	ans[m] = (ll)n * (n - 1) / 2; //��Сע��תlong long
	init();//��ʼ�����鼯
	for(int i = 0; i < m; i++)
//		cin >> a[i] >> b[i];//����
		scanf("%d%d",&a[i],&b[i]);
	for(int i = m - 1; i >= 0; i--) { //�Ӻ���ǰ
		int f_a = Find(a[i]), f_b = Find(b[i]);//���ڵ� 
		if(f_a != f_b) {
			//����һ���
			ans[i] = ans[i+1] - (num[f_a] * num[f_b]);
			Union(a[i], b[i]);
		} else ans[i] = ans[i+1];
	}
	for(int i = 1; i <= m; i++)
//		cout << ans[i] << endl;
		printf("%lld\n",ans[i]);
}
