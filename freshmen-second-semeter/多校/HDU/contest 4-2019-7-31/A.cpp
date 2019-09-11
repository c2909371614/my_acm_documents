#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int fa[N];
int run(int x) {
	int t = 1;
	while(x & 1) {
		t <<= 1;
		x >>= 1;
	}
	return t;
}
void solve() {
	cin >> n; 
	if(n == 2) {
		printf("0\n1\n");
		return;
	}
	if(n == 3) {
		printf("1\n1 1\n");
		return;
	}
	int val = 0;
	for(int i = 2; i <= n; i += 2) fa[i] = 1;
	for(int i = 3; i <= n; i++) {
		if((i&(i + 1)) == 0) {
			if(i + 1 <= n) fa[i] = i + 1;
			else val++, fa[i] = 1;
		} else {
			fa[i] = run(i);
		}
	}
	printf("%d\n", val);
	for(int i = 2; i <= n; i++)
		printf("%d%c", fa[i], " \n"[i == n]);
}
int  main() {
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}


