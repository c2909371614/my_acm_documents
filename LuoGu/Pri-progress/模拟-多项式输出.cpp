#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const  int INF = 0x3f3f3f3f;
void solve(){
	int n;
	cin >> n;
	bool flag = false;
	for(int i = n; i >= 0; i--){
		int a;
		cin >> a;
		if(a != 0){
			if(a >= 0 && flag) 
				cout << "+";
			if(a != 1 && a != -1)
				cout << a;
			if(a == -1) cout << "-";
			if(i != 0) {
				cout << "x";
			}
			else {
				if( a == -1 || a == 1)
					cout << 1;
				continue;
			}
			if(i != 1) cout << "^" << i;
			flag = true;
		}
	}
	cout << endl;
}
int main(){
	solve();
	return 0;
}