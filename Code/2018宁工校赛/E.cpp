#include<bits/stdc++.h>
using namespace std;
const int maxM=1e5+5;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int a[maxM],n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		if(n>1)
			sort(a,a+n,cmp);
		int ans=0;//cout<<"ok"<<endl;
		for(int i=n-1;i>n-6&&i>=0;i--)
			if(a[i]>0)ans+=a[i];
		cout<<ans<<endl;
	}
}
