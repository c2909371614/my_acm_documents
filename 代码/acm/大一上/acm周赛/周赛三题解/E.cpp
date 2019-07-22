#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+20;

int cnt[N];

int ok(int x){
	int tmp[10];
	memset(tmp, 0, sizeof tmp);
	while(x){
		if(tmp[x%10]) return 0;
		tmp[x%10]++;
		x/=10;
	}
	return 1;
}

void init(){
	for(int i=1;i<=100000;i++){
		if(ok(i)) cnt[i] = 1;
		cnt[i] += cnt[i-1]; 
	}
}

int main(){
	init();
	int T;
	cin >> T;
	while(T--){
		int l, r;
		cin >> l >> r;
		cout << cnt[r] - cnt[l-1] << endl;
	} 
	return 0;
}
