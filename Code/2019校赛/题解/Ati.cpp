#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

int t, n, d;
ll sum[100005], Max;
struct node {
	int x, y;
} a[100005];

bool cmp(node a, node b) {
	return a.x < b.x;
}

bool f(int l, int r) {
	if(a[r].x - a[l].x <= 2 * d) return true;
	return false;
}

int main() {
//scanf("%d", &t);
	cin >> t;
	while(t--) {       //scanf("%d%d", &n, &d);
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			//scanf("%d", &a[i].x);
			cin >> a[i].x;
		}
		for(int i = 1; i <= n; i++) {
			//scanf("%d", &a[i].y);
			cin >> a[i].y;
		}
		sort(a + 1, a + n + 1, cmp);
		memset(sum, 0, sizeof(sum));
		Max = 0;
		for(int i = 1; i <= n; i++) {
			sum[i] = sum[i-1] + a[i].y;
		}
		for(int i = 1; i <= n; i++) {
			int l = i, r = n, R = i, mid;
			while(l <= r) {
				mid = (l + r) / 2;
				if(f(i,mid)) {
					R = mid;
					l = mid + 1;
				}                else {
					r = mid - 1;
				}
			}
			Max = max(Max, sum[R] - sum[i-1]);
		}
		cout << Max << endl;
	}
} 
