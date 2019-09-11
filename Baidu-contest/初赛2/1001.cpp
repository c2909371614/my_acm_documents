#include<bits/stdc++.h>
using namespace std;
int ans[105];
int factor[105][105];
//int n;
int sum;
void get_factor() {
	memset(factor, 0, sizeof(factor));
	for(int i = 1; i < 105 ; i++) {
		for(int j = 1; j <= i; j++) {
			if(i % j == 0) factor[i][j] = 1;
		}
	}
}
void get_sum(int a){
	sum = 0;
	while(a){
		sum += a % 10;
		a /= 10;
	}
}
void solve() {
	memset(ans, 0, sizeof(ans));
	int a;
	cin >> a;
	int n = 0;
	get_sum(a);
	for(int i = 1; i <= sum; i++){
		if(a % i == 0 && factor[sum][i])
			n++, ans[i] = 1;
	}
	cout << n << endl;
	int count = 0;
	for(int i = 0; i < 105; i++){
		if(ans[i]){
			cout << i;
			count++;
			if(count != n) cout << " ";
		} 
		
	}
	cout << endl;
}
int main() {
	int T;
	cin >> T;
	get_factor();
	while(T--) {
		solve();
	}
}
