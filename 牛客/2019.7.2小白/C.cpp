#include<bits/stdc++.h>
#define ll long long
//#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e3 + 5;
const ll INF = 0x3f3f3f3f;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int high[MAX];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i  < n; i++) {
		cin >> high[i];
	}
	int ans = 0;
	bool flag = true;
	while(m--) {
		ans = 0;
		int w;
		cin >> w;
		flag = true;
		for(int i = 0; i < n; i++) {
			if(high[i] > w&&flag){
				ans++;
				flag = false;
			}
			else if(high[i] <= w){
				flag = true;
				//cout << "o"<<endl;
			}
		}
		cout << ans << endl;
	}

}
