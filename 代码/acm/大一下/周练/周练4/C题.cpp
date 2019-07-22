#include<bits/stdc++.h>
#define ll long long
const int maxM=1e5+5;
using namespace std;
int ans=0;
int dfs(int l,int r,int a[]){
	//int ans=r-l+1;
	if(l==r){
		ans=max(ans,r-l+1);
		return 0;
	}
	int flag=true;
	for(int i=l;i<r;i++){
		if(a[i]>a[i+1]){
			flag=false;
			break;
		}	
	}//cout<<ans<<endl;
	if(flag){
		ans=max(ans,r-l+1);
	}
		
	dfs(l,(l+r)/2,a);
	dfs((l+r)/2+1,r,a);
	
}
int main(){
	int n;
	cin>>n;
	int a[maxM];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,n-1,a);
	cout<<ans<<endl;
	
} 
