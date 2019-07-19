#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1e5 + 5;

int num[55][55];
char pic[55][55];
int n, m;
//void dfs
int main()
{
	memset(pic, '.', sizeof(pic));
	memset(num, 0, sizeof(num)); 
	cin >> n >> m; 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> pic[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(pic[i][j] == '#')
			{
				if(pic[i-1][j] == '#')num[i][j]++;
				else if(pic[i+1][j] == '#')num[i][j]++;
				else if(pic[i][j+1] == '#')num[i][j]++;
				else if(pic[i][j-1] == '#')num[i][j]++;
			}
		}
	int Min = MAX; 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(pic[i][j] == '#')Min = min(Min, num[i][j]);
	cout << Min << endl;
}

