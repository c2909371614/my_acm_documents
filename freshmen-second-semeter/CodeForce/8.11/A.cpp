#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ch[10];
	memset(ch, 0, sizeof(ch));
	int pos = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; s[i] == 'L' && j < 10 ; j++){
			if(ch[j] == 0){
				ch[j] = 1;
				break;
			}
		}
		for(int j = 9; s[i] == 'R' && j >= 0 ; j--){
			if(ch[j] == 0){
				ch[j] = 1;
				break;
			}
		}
		if(s[i] >= '0' && s[i] <= '9')
			ch[s[i] - '0'] = 0;
	}
	for(int i = 0; i <= 9; i++)
		cout << ch[i];
	cout << endl;
	return 0;
} 