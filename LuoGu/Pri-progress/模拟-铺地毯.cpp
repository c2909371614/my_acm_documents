#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const  int INF = 0x3f3f3f3f;
int n;
struct Carpet{
	int a, b, g, k;
	Carpet(){
		a = b = g = k = -1;
	}
}carp[N];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++)//输入
		cin >> carp[i].a >> carp[i].b >> carp[i].g >> carp[i].k;
	int x, y;
	cin >> x >> y;
	int ans = -1;//没有地毯覆盖输出-1
	for(int i = n; i > 0; i--){
		if(x >= carp[i].a && x <= carp[i].a + carp[i].g 
			&& y >= carp[i].b && y <= carp[i].b + carp[i].k){
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}
int main()
{
	solve();
}
