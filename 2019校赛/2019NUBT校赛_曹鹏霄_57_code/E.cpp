#include<bits/stdc++.h>
#define ll long long
const int MAX=1e5+5;
using namespace std;
ll ans[100];
void calc()
{
	ans[0]=1;
	ans[1]=1;
	ans[2]=2;
	for(ll i=3;i<51;i++){
		ans[i]=ans[i-1]+ans[i-2]+1;
	}
}
int main()
{
	int T;
	cin>>T;
	calc();
	while(T--){
		ll n;
		cin>>n;
		cout<<ans[n]<<endl;
	}
	
}
