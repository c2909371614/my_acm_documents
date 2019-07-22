#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int a[31][31],n;
	a[1][1] = 1; a[2][1] = 1; a[2][2] = 1;
	for (int i = 3; i <= 30; i++)
	{
		a[i][1] = 1;
		a[i][i] = 1;
		for (int j = 2; j <i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (j == 1) cout << a[i][j];
				else
				cout << " "<<a[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	 return 0;
}
