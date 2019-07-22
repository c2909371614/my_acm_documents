#include<bits/stdc++.h>
#define N 2e5
#define ll long long
using namespace std;
bool cmp(int a,int b){
	return a>b?true:false;
}
int main(){
	ll n,m,k;
//	
	ll a[200000];
//	cin>>n>>m>>k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);//从小到大
	for(int i=1;i<=n;i++)
		cout<<a[i]<<"0"; 
//	ll sum=m/(k+1)*(k*a[n]+a[n-1])+m%(k+1)*a[n];
//	while(m>0){
//		//k1=k;
//		//printf("k=%d m=%d 00\n",k,m);
//		while(m<k){
//			sum+=a[n];m--;//cout<<right<<"m="<<m<<" "<<sum<<endl;
//			if(m==0)break;
//		}
//		if(m==0)break;
//		sum+=a[n-1];m--;//cout<<right<<"m="<<m<<" "<<sum<<endl;
//		if(m==0)break;	
//	} 
int sum=1;
	cout<<sum<<endl;
}
