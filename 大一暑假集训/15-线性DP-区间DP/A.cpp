#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e3+5;
int DP[MAX], maxx = 0, maxxx = -1;
int a[MAX], b[MAX];
int n, m;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		memset(DP, 0, sizeof(DP));
		maxxx = -1;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cin >> m;
		for(int i = 0; i < m; i++)
			cin >> b[i];
		for(int i = 0; i < n; i++)
		{
			maxx = 0;//��ʼ�����ȷ�ֹ��ĸ�С�ĸ��� 
			for(int j = 0; j < m; j++)
			{
				if(a[i] == b[j])
					DP[j] = maxx + 1;//������ȸ���d[j] 
				if(a[i] > b[j])
					maxx = max(maxx, DP[j]);//�ҵ���a[i]С��a[j]��d[j]������maxx 
				maxxx = max(maxxx, DP[j]);
			}
			
		}
		cout << maxxx << endl;
		if(T)cout << endl;
	}
	return 0;
 } 
