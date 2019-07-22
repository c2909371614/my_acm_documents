#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX=1e5+5;

struct node {
	ll w,m;
} A[MAX];
bool cmp(struct node a,struct node b) {
	return a.w<b.w;
}
ll n,d,sum[MAX];
ll double_search(ll l,ll r,ll i) { //i固定不变与初始l相等

	ll mid=-1;
	ll ans=-1;
	while(l<=r) {
		mid=(l+r)/2;
		if(A[mid].w-A[i].w<=2*d) { //mid与l的差值
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	return ans;

	//return -1;
}
int main() {
	ll T;
	cin>>T;
	while(T--) {
		cin>>n>>d;
		memset(sum,0,sizeof(sum));
		for(ll i=0; i<n; i++) {
			cin>>A[i].w;
		}
		for(ll i=0; i<n; i++)
			cin>>A[i].m;
		sort(A,A+n,cmp);
		sum[0]=A[0].m;//把第一个赋值
		for(ll i=1; i<n; i++) //从第二个开始做前缀和
			sum[i]=sum[i-1]+A[i].m;
//		for(ll i=0; i<n; i++) //输出测试
//			cout<<sum[i]<<" ";
		ll Max=0;
		for(ll i=0; i<n; i++) {
			ll pos=double_search(i,n-1,i);
			//cout<<"pos:"<<pos<<"i:"<<i<<endl;
			if(pos!=-1)
				Max=max(Max,sum[pos]-sum[i]+A[i].m);
			 
		}
		cout<<Max<<endl;
	}

}

