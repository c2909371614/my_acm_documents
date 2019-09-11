#include<bits/stdc++.h>
using namespace std;
int index[55];
bool equal(string s1, string s2) {
	int ch1[26], ch2[26];
	memset(ch1, 0, sizeof(ch1));
	memset(ch2, 0, sizeof(ch2));
	int len1 = s1.size();
	int len2 = s2.size();
	if(len1 != len2) return false;
	for(int i = 0; i < len1; i++){
		ch1[s1[i] - 'a']++;
		ch2[s2[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++)
		if(ch1[i] != ch2[i])return false;
	return true;
}
int alph[26];
int my_find(char ch, string s){
	int pos = ch - 'a';//下标 
	alph[pos] = s.find(ch, alph[pos]) + 1;
	cout << "pos " << alph[pos] << endl;
	return alph[pos] - 1;
}
void solve() {
	memset(index, -1, sizeof(index));
	int n, m;
	cin >> n >> m;
	string s1, s2;
	bool flag = false;//长度不等
	for(int i = 0; i < n; i++) {
		memset(alph, 0, sizeof(alph));//初始化字母下标 
		cin >> s1 >> s2;
		if(!equal(s1, s2)) {//答案不存在 
			flag = true;
			continue;	
		}
		for(int i = 0; i < m; i++){
			//if(index[i] == -1)
				index[i] = my_find(s1[i], s2);
//			else{
//				
//			}
		} 
	}
	if(flag){
		cout << -1 << endl;
		return;
	}
	for(int i = 0; i < m; i++){
		cout << index[i] + 1;
		if(i != m-1) cout << " ";
	}
	cout << endl;
}
int main() {
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}
