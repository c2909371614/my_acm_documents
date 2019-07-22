#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxM=1e5+5;
int main(){
	int T;
	cin>>T;
	while(T--){
		string s,s1;
		cin>>s;
		s1+=s[0];
		for(int i=1;i<s.size();i++){
			switch(s[i]){
				case 'a':case 'e':
				case 'i':case 'o':
				case 'y':case 'u':break;
				default:s1+=s[i];
			}
		}
		cout<<s1<<endl;
	}
}
