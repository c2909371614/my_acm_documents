#include<bits/stdc++.h>
#define ll long long
const int MAX=1e5+5;
using namespace std;
struct sum{
	int a;
	int b;
};
bool cmp(sum A, sum B){
	return A.a>B.a;
}
int main()
{
	int T;
	cin>>T;
	int n,m;
	struct sum M[MAX];
	while(T--)
	{
		cin>>n>>m;
		for(ll i=0;i<n;i++)
			cin>>M[i].b;
		for(ll i=0;i<n;i++)
			cin>>M[i].a;
		sort(M,M+n,cmp);
		ll ans=0,i=0;
		ll ntemp=m;
		while(ntemp--)
		{
			ans+=M[i].a;
			M[i].b--;
			if(M[i].b==0)i++;
		}
		cout<<ans<<endl;
	}
 } 
