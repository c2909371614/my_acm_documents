#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int a[3];
	while(cin>>a[0]>>a[1]>>a[2]){
		sort(a,a+3,cmp);
		int n=a[2]-a[0];
		int m=a[2]-a[1];
		int ans=0;
		ans+=m/2+n/2;
		//cout<<" "<<ans<<endl;
		m%=2;
		n%=2;
		if(n==1&&m==1)ans++;
		else if(n==1||m==1)ans+=2;
		cout<<ans<<endl;
	}
}
