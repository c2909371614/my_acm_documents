#include<bits/stdc++/h> 
#define ll long long
#define N 10010

#define FAST_IO ios::sync_with_stdio(false)
using namespace std;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double pi = 3.141592653;
using namespace std;

int main() {
	int T;
	cin>>T;
	while (T--) {
		ll a1, a2, a3;
		cin>>a1>>a2>>a3;
		if(a1==0){
			cout<<1<<endl;
			continue;
		}
		if(a1+a2*2+1<5 || a3==0) cout<<a1+a2*2+1<<endl;
		else cout<<a1+a2*2+a3*5+1<<endl;
	}
}
