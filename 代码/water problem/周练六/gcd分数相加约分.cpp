#include<iostream>
#include<cstdio>
using namespace std; 
int gcd(int a,int b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main()
{
	int T,a,b,c,d,e,f;
	cin>>T;
	while(T--){
		cin>>a>>b>>c>>d;
		f=d*b;
		e=a*d+c*b;
		int ans=gcd(e,f);
		f/=ans;
		e/=ans;
		cout<<e<<' '<<f<<endl;
	}
	
 } 
