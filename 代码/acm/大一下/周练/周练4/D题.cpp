#include<bits/stdc++.h>
using namespace std;
const int maxM=1e5+5;
#define ll long long 
struct inf{
	ll a,b;
};
int cmp(inf A,inf B){
	return A.a-A.b>B.a-B.b?1:0;
}
int main(){
	struct inf s[maxM];
	int n;
	cin>>n;
	//int a[maxM],b[maxM];
	ll ans=0;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].b;
		ans+=n*s[i].b-s[i].a;
		
	}
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++){
		ans+=(s[i].a-s[i].b)*(i+1);
	}
	cout<<ans<<endl;
} 
