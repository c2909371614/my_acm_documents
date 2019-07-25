#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
int divide_seach(int l,int r,int aim) {
	int mid=(l+r)/2;
	while(l>r) {
		if(mid==aim)return mid;
		else if(mid>aim)r=mid-1;
		else if(mid<aim)l=mid+1;
	}
	return -1;
}
int main() {
	int T;
	int a[MAX];
	cin>>T;
	while(T--) {
		int n;
		cin>>n;

		for(int i=0; i<n; i++)
			cin>>a[i];

		int max=2,min=2;
		bool flag=true;//记录是否存在结果
		for(int i=n-1; i>0; i--) {
			flag=true;//记录是否存在结果每次都要记录并初始化
			for(int j=1;;j++) {
				if(a[i-1]*j>min+a[i]-1){
					flag=false;
					break;
				}
				else if(a[i-1]*j<min);
				else {
					min=a[i-1]*j;
					break;
				}
			}

			if(flag==false) {
				cout<<-1<<endl;
				break;
			}
			max=(max+a[i]-1)/a[i-1]*a[i-1];
			
			//cout<<"max:"<<max<<" min:"<<min<<endl;
		}
		if(flag)
			cout<<min<<" "<<max+a[0]-1<<endl;
	}
}
