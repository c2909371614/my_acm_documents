#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#define ll long long int
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 2e6+5;
int DP[MAX];
int a[MAX];

int main()
{
	cout << (((ll)1<<63)-1) << endl;  
	int p;
	cin >> p;
	bool flag = true;
	int ans = 0;
	for(int i = 1; i <= p; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= p; i++)
	{
		if(flag)
		{
			while(i < p && a[i] <= a[i+1])
				i++;
			ans += a[i];
			flag = false;
		}
		else {
			while(i < p && a[i] >= a[i+1])
				i++;
			ans -= a[i];
			flag = true;
		}
	}
	if(flag) ans += a[p];//最后一个为谷底的话就不要减了，加回来 
	cout << ans << endl;	
  }  
