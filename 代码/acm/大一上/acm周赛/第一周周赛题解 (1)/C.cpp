#include <iostream>
using namespace std;
int a[1005];
int j=0;

void init()     //方法一：打表求出满足的WC数 
{
	int n;
	bool flag=true;
	for(int i=2;i<=1000;i++){
		n=i;
		flag=true;
		while(n>0){
			if(n%10!=4&&n%10!=7){
				flag=false;
				break;
			}
			n/=10;
		}
		if(flag==true) a[j++]=i;
	}
}

int num[] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777}; //方法二：手动计算 

int main()
{
	init();
	int n;
	cin>>n;
	for(int i=0;i<j;i++){
		if(n%a[i]==0){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
