#include<bits/stdc++.h>
#define N 100005
using namespace std;
int main()
{
	int t;
	cin>>t; 
	string s;
	int a[N];
	while(t--){
		cin>>s;
		int count=1;
		for(int i=0;i<s.size();i++)
			a[i]=0;
		for(int i=0;i<s.size();i++)
			if(s[i]=='w'&&s[i+1]=='c')
				a[count++]=i+1;//get the position of 'w'
		a[count]=s.size();
		long long ans=0;
		for(int i=1;i<count;i++) {
			ans+=(a[i]-a[i-1])*(a[i+1]-a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
