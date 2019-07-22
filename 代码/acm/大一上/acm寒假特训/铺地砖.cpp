#include<bits/stdc++.h>
#define pi 3.14159265359 
using namespace std;
int main(){
	double n,r,R;
	cin>>n>>r;
	R=r*(sin(pi/n)/(1-sin(pi/n)));
	printf("%.7f",R);
}
