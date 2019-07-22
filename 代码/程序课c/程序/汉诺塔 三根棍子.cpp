#include<stdio.h>
#include<iostream>
using namespace std;
double fun(double n)
{
	//int times;
	if(n==1)return 1;
	else return 2*fun(n-1)+1;
 
 } 
 int main()
 {
 	double time;
 	cin>>time;
 	cout<<fun(time);
 }
 
 
