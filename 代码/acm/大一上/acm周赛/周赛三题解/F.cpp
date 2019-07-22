#include <iostream>
using namespace std;
const int N = 1e5+20;

int n;
string s;

int main(){
	cin >> s;
	n = s.size();
	s = s + s;
	int len = 0, cnt = 0;
	for(int i=0;i<2*n;i++){
		if(i==0||s[i]==s[i-1]){
			len = max(len, cnt);
			cnt = 1;
		}
		else{
			cnt++;
		}
	}
	len = max(len, cnt);
	cout << min(n, len) << endl;
	return 0;
}
