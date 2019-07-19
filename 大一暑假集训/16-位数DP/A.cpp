#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e6+5;
int DP[MAX], maxx = 0, maxxx = -1;
int a[MAX], s[8];
int n, m, degree;
void turn(int x)
{
	memset(s, 0, sizeof(s));
	int i = 0;
	while(x)
	{
		s[++i] = x%10;//防越界 
		x /= 10;
	}
	degree = i;//记录位 
}
void select()
{
	
	memset(a, 0, sizeof(a));
	for(int i = 0; i < MAX; i++)
	{
		turn(i);
		for(int j = degree; j > 0; j--)
		{
			if(s[j] == 4 ||(s[j] == 6 && s[j-1] == 2))
				a[i] = 1;
		}
	}
}
int main()
{
	FAST_IO; 
	select();
	//cout << a[16162] << endl;
	while(cin >> n >> m && (n != 0 || m != 0))
	{
		int ans = 0;
		for(int i = n; i <= m; i++)
			if(!a[i])ans++;
		cout << ans << endl;
	}
 } 
