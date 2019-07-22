#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxM=1e5+5;
int lucky[120];
int myLucky(){
	memset(lucky,0,sizeof(lucky));
	for(int i=0;i<120;i++){
		if(i%7==0&&i%4!=0){
			lucky[i]=1;
		}
	}
//	for(int i=0;i<120;i++)
//		cout<<lucky[i]<<" ";
}
int main(){
	int T;
	int a;
	cin>>T;
	myLucky();
	while(T--){
		cin>>a;
		for(int i=a;;i++){
			if(lucky[i]==1){
				cout<<i<<endl;
				break;
			}		
		}	
	}
}
