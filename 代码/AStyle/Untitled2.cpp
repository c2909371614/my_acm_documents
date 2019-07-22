#include<bits/stdc++.h>
using namespace std;
const int maxM=1e5+5;
int main() {
	int T;
	cin>>T;
	int count=0;
	while(T--) {
		int n;
		cin>>n;
		count++;
		int l=0,r=0,ans=0,end_ans=-1001,end_l,end_r;
		int a[maxM];
		for(int i=0; i<n; i++) {
			cin>>a[i];
		}
		for(int i=0; i<n;) {
			ans+=a[i];

			if(ans>end_ans) {
				end_ans=ans;
				end_l=l;
				end_r=i;
			}
			if(ans<0) {
				ans=0;
				l=i;

			}
			//cout<<ans<<" "<<end_ans<<" "<<i<<endl;
		}
		cout<<"Case "<<count<<":"<<endl;
		cout<<end_ans<<" "<<end_l+1<<" "<<end_r<<endl;
		if(T!=0)cout<<endl;
	}
}

