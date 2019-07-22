#include<bits/stdc++.h>
using namespace std;
int beautifulNum[1000];
int selectNum() {
	int n,same[10],i;
	memset(beautifulNum,0,sizeof(beautifulNum));
	for(i=0; i<1000; i++) { //cout<<i<<endl;
		n=i;
		memset(same,0,sizeof(same));
		while(n) {
			same[n%10]++;
			n/=10;
		}
		int sum=0;
		for(int j=1; j<10; j++)
			while(same[j]--) {
				sum+=j*j*j;
			}
		if(i==sum)beautifulNum[i]=1;
	}

}
int main() {
	int x,y;
	selectNum();
	int flag=1;
	int a[1000];

	//bool last=true;
	while(cin>>x>>y) {
		//memset(a,0,sizeof(a));
		memset(a,0,sizeof(a));
		int j=0;
		flag=1;
		for(int i=x; i<=y; i++) {
			if(beautifulNum[i]==1) {
				a[j++]=i;
				flag=0;
			}
		}
		if(flag==1)cout<<"no"<<endl;
		else {
			for(int i=0; i<1000; i++) {
				if(a[i]!=0) {
					cout<<a[i];
					if(a[i+1]==0)cout<<endl;
					else cout<<" ";
				}

			}
		}
	}

}
