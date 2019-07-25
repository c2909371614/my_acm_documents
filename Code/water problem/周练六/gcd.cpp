#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b){
		while(true){
			if(b==0){
				printf("%d\n",a);
				break;
			}
			else {
				int temp=a;
				a=b;b=temp%b;
			}
		}
	}
}
