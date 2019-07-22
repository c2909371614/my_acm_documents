#include<bits/stdc++.h>
#define ll long long
const int MAX=1e5+5;
using namespace std;
int main()
{
	int T;
	cin>>T;
	int a[MAX],ans=0;
	while(T--)
	{
		cin>>a[T];
		if(a[T]==1)ans++;
	}
	cout<<ans<<endl; 
}
