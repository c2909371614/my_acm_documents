#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int T;
	cin>>T;
	while(T--) {
		long long ans=0;
		cin>>s;
		ans+=-((long long)(s[0]-'0')<<(s.size()-1));
		cout<<ans<<endl;
		for(int i=1; i<s.size()-1; i++) {
			ans+=(long long)(s[i]-'0')<<(s.size()-i-1);

		}
		cout<<ans<<endl;
	}


}

