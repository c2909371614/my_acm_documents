#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long maxM=2e5+5;
struct Guest{
	ll h;
	int flag;
	int gender;
	bool ready;
};
int cmp(struct Guest a,struct Guest b){
	return a.h<b.h ?1:0;
}
int main(){
	int T,m,n;
 	struct Guest *a=new struct Guest[maxM]/*,b[maxM],tot[maxM]*/;
 	
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++){ 
			cin>>a[i].h ;
			a[i].gender =1;//man
		} 
		for(int i=0;i<m;i++){ 
			cin>>a[i+n].h ;
			a[i+n].gender =0;//women
		}
		for(int i=0;i<n;i++)
			cin>>a[i].flag ;
		for(int i=0;i<m;i++)
			cin>>a[i+n].flag ;
		sort(a,a+n+m,cmp);
		for(int i=0;i<n+m;i++){
			a[i].ready=true;
			cout<<a[i].h<<endl;
		}
		int temp=n-m;
		int ans=0;
		for(int i=0;i<m+n;i++){
			if(a[i].gender==1){
				if(a[i].flag==0){
					
				}
			} 
		}
	}
	
	delete []a;
}
