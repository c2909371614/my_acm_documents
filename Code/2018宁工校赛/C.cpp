#include<bits/stdc++.h>
const int maxM=1e5+5;
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int divide_search(int a[],int l,int r,int n){
	int mid=(l+r)/2;
	while(l<=r){
		//cout<<n<<" "<<a[mid]<<endl;
		if(n==a[mid])
			return mid;
		else if(n>a[mid]){
			l=mid+1;
			mid=(l+r)/2;
		}
		else{
			r=mid-1;
			mid=(l+r)/2;
		}
	}
	return -1;
} 
int main(){
	//std::ios::sync_with_stdio(false);
	int T;
	//cin>>T;
	scanf("%d",&T);
	while(T--){
		int a[maxM],n,q;
		//cin>>n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			//cin>>a[i];
			scanf("%d",&a[i]);
		sort(a,a+n,cmp);
		//cin>>q;
		scanf("%d",&q);
		int m;
		for(int i=0;i<q;i++){
			//cin>>m;
			scanf("%d",&m);
			//cout<<divide_search(a,0,n-1,m)+1<<endl;
			printf("%d\n",divide_search(a,0,n-1,m)+1);
		}
		
		return 0;
	}
}
