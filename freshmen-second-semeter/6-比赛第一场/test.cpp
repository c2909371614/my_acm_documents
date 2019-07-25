#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int INF = 1e9 + 7;

string a, b;

int main() {
	cin >>a >> b;
	int n = a.length();
	if(n < b.length()) {
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		cout <<a << '\n';
	} else {
		sort(a.begin(), a.end());
		for(int i = 0; i < n; i++) { // 0到size-1
			int j = i;
			for(; j < n && a.substr(0, i) + string(1, a[j]) + a.substr(i, j-i) + a.substr(j + 1) <= b; j++); //满足j++的条件
			j--;
			a = a.substr(0, i) + string(1, a[j]) + a.substr(i, j - i) + a.substr(j + 1);
			cout << " a:" << a << endl;
		}
		cout << a << '\n';
	}
	return 0;
}
