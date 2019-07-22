#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxM=1e5+5;
ll myMax(ll a,ll b,ll c){
	ll max=a>b?a:b;
	return max>c?max:c;
}
ll myMin(ll a,ll b,ll c){
	ll min=a<b?a:b;
	return min<c?min:c;
}
int main(){
	int T;
	cin>>T;
	int a[maxM];
	while(T--){
		ll ans=-11,min1[maxM],max1[maxM];
		ll n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			if(i==0){
				min1[i]=a[i];
				max1[i]=a[i];
			}
			else {
				max1[i]=myMax(a[i],max1[i-1]*a[i],min1[i-1]*a[i]);
				min1[i]=myMin(a[i],max1[i-1]*a[i],min1[i-1]*a[i]);
			}
			if(max1[i]>ans)
				ans=max1[i];
			//cout<<max1[i]<<" "<<min1[i]<<endl;	
		}
		cout<<ans<<endl;
	}
}
