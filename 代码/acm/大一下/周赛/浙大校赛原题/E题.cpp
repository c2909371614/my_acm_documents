#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long maxM=1e9+5;
int main(){
	int T,n;
	ll a[105],b[105];
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		ll temp=0;
		for(int i=n-1;i>=0;i--){
			temp+=b[i]-a[i];
			if(temp<0){
				cout<<"No"<<endl;
				break;
			}
			//cout<<"temp "<<temp<<endl;
		}
		if(temp>=0)
			cout<<"Yes"<<endl;
	}
	 
} 
