#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		bool flag=false;
		int a[14],temp[5];
		memset(temp,0,sizeof(temp));
		for(int i=0;i<14;i++){
			cin>>a[i];
			if(i<7&&a[i]==0)
				flag=true;
			temp[a[i]]++;
		}
		if(flag==false){
			cout<<"NO"<<endl;
			//return 0;
		}
		else if(temp[3]==0)
			cout<<"NO"<<endl;	
		else if(temp[4]==0&&(temp[1]!=0||temp[2]!=0))
			cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}
