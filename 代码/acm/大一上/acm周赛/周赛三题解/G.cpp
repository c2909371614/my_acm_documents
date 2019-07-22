#include <iostream>
using namespace std;
const int N = 100+20;

int n, m;
int a[N];

int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i+m-1<=n;i++){
			int ans = 0;
			for(int j=0;j<m;j++){
				ans += a[i+j];
			}
			cout << ans;
			if(i+m-1==n) cout << endl;
			else cout << ' '; 
		}
	}
	return 0;
}
