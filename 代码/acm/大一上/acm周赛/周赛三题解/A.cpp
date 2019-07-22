#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;

int n;
int a[N];

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	cout << a[(n+1)/2] << endl;
	return 0;
}
