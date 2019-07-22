#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxM=1e5+5;


int main(){
	int T;
	cin>>T;
	int temp[3]={0,1,0};
	while(T--){
		string a,b;
		int ans_a=0,ans_b=0;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			ans_a+=a[i]-'0';
		}
		ans_a=(int)abs(ans_a-1)%3;
		for(int i=0;i<b.size();i++){
			ans_b+=b[i]-'0';
		}
		ans_b%=3;

		cout<<temp[(int)abs(ans_b-ans_a)]<<endl;
		//cout<<ans_a<<ans_b<<endl;
	
		
	}
} 
