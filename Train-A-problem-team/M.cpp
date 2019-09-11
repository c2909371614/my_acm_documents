#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false);
using namespace std;
const int N = 1e6 + 5;

int my_m(int a, int b){
	if(a >  b)return a;
	return b;
}
int main() {
	string s, s2, sub = "";
	int n, m, ans;
	while(cin >> n >> m) {
		cin >> s >> s2;
		bool flag = true;
		for(int i = 0; i < n; i++) {
			if(s.substr(i) > s2) {
				ans = n - i;
				flag = false;
				break;
			}
		}
		for(int j = 0; j < n ; j++) {
			sub = "";
			for(int i = j; i < n; i++) {
				if(sub + s.substr(i) > s2) {
//					cout << sub << "-" << s.substr(i) << "-" << s2 << endl;
					printf("%d\n",my_m(n - i + sub.size(), ans) );
					flag = false;
					break;
				} else if(s[i] == s2[sub.size()]) {
					sub += s[i];
				}
			}
			if(!flag)break;
		}

		if(flag) printf("-1\n");
	}

}


