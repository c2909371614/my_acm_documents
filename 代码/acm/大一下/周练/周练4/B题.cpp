#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxM=1e5+5;
int myFind(string s,char ch,int n) { //����s�е�n��ch��λ��
	int pos=-1;
	for(int i=0; i<n; i++) {
		pos=s.find(ch,pos+1);
				
	}
//	cout<<pos;
	return pos;
}
int main() {
	int n,num_8=0;
	string s;
	cin>>n;
	cin>>s;
	for(int i=0; i<n; i++) {
		if(s[i]=='8')
			num_8++;
	}
	if(num_8<(n-11)/2+1){
		cout<<"NO"<<endl;
		return 0;
	}
		
	if(myFind(s,'8',(n-11)/2+1)>n-11)
		cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	
}
