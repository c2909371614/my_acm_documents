#include<bits/stdc++.h>
#define ll long long
const int MAX=1e5+5;
using namespace std;
struct star{
	int s;
	int x,y;
};
int main()
{
	int T;
	cin>>T;
	star a[MAX];
	int n,r;
	while(T--){
		cin>>n>>r;
		for(int i=0;i<n;i++)
			cin>>a[i].s>>a[i].x>>a[i].y; 
		
		int ans=0;
		for(int i=1;i<n;i++){
			if(a[i].s<a[0].s&&sqrt(pow(a[i].x-a[0].x,2)+pow(a[i].y-a[0].y,2))<=r)
				ans++;
		}
		cout<<ans<<endl;
	}
}
