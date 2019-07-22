#include <iostream>
using namespace std;
long long a[200005];
long long b[200005];

int main()
{
	int n,m;
	long long k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j=1;
	long long ans=0;
	for(int i=1;i<=m;i++){
		b[i]=k;
	}
	for(int i=n;i>=1;i--){
		if(b[j]>=a[i]){
			b[j]-=a[i];
			ans++;
		}
		else if(b[j]<a[i]){
			j++;
			if(j==m+1) break;
			b[j]-=a[i];
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
