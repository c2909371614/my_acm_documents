#include<iostream>
#include<cstdio>
using namespace std;
void my_swap(int *x,int *y){
	int temp=*x;
	*x=*y;*y=temp;
}
void my_sort(int *p,int l,int r)
{
	int x=l,y=r,temp,flag=p[l];
	while(y>x){
		while(y>x&&p[y]>=flag)
			y--;
		if(y>x)
			my_swap(p+x,p+y);
		while(y>x&&p[x]<=flag)
			x++;
		if(y>x)
			my_swap(p+x,p+y);	
	}
	if(x-1>l)my_sort(p,l,x-1);
	if(y+1<r)my_sort(p,x+1,r);
}
int main()
{
	int a[100],n;
	cin>>n;
	int N=n;
	while(N--)
		cin>>a[N];
	int l=1,r=n;
	my_sort(a,l,r);
	N=n;
	while(N--)
		cout<<a[N]<<' ';
 } 
