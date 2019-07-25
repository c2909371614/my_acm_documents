#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#define ll long long
using namespace std;
int const MAX=1e5+5;
vector<int> ver[MAX],edge[MAX];
int node[MAX];

int main()
{
	ll T;
	ll n,m;
	ll x,y; 
	cin>>n>>m;
	ll min;
	for(ll i=1;i<=n;i++){
		if(i*(i-1)>=2*m){
			min=i;
			break;			
		}	
	}
	if(m==0)min=0;
	cout<<max(n-m*2,(ll)0)<<" "<<n-min<<endl;
 } 
