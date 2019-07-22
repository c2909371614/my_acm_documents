#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,i,j,ans;
int main(){
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
  		for(i=1;i<=n;i=j+1){
    		j=n/(n/i); 
    		ans+=n/i*(j-i+1);
  		}
  		cout<<ans<<endl;
	}
  
}
