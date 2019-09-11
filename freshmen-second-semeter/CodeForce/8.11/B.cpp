#include<bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false)
#define ll long long 
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f; 
int main()
{
	int T;
	cin >> T;
	while(T--){
		int n, m, k;
		cin >> n >> m >> k;
		int sum = m;
		int a[105];
		memset(a, 0, sizeof(a));
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int flag = true;
		for(int i = 0; i < n-1; i++){
			if(a[i+1] - a[i] <= k + sum){
				sum = sum +  + a[i] - max(a[i+1] - k, 0); 
			}
			else {
				flag = false;
				break;
			}
		}
		if(flag)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
 } 
