#include<bits/stdc++.h>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e5 + 5;
struct node {
	long long pos, num;//位置和居住人数 
} a[MAX];

long long n, s, ans = 0;

bool cmp(node x, node y) {
	return (x.pos < y.pos);
}

int main() {
	FAST_IO;
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i].pos >> a[i].num;
	sort(a + 1, a + n + 1, cmp);//按照位置从小到大排序 
	ll left = 1, right = n;//定义左右边界 
	while (left <= right) {
		if (a[right].pos <= s) {//全部在最左边 
			ans += (s - a[left].pos);
			break;
		}
		if (a[left].pos >= s) {//全部在最右边 
			ans += (a[right].pos - s);
			break;
		}
		ans += (a[right].pos - a[left].pos);//最后一步的路程 
		
		/*最边上的人，人数更小的一边反而会投靠另一边，
		故而可以这样处理（例）：最右边的人数加上最左边
		的人数，ans += 两者间路径 */ 
		if (a[left].num >= a[right].num) { 
			while (left < right && a[left].num >= a[right].num)
				a[left].num += a[right--].num;
		} 
		else {
			while (left < right && a[right].num > a[left].num)
				a[right].num += a[left++].num;
		}
	}
	cout << ans << endl;
	return 0;
}

