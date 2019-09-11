#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false);
using namespace std;
const int N = 1e6;
const int M = 2e6 + 6;
int mian()
{
	int n;
	scanf("%d", &n);
	int x[N], y[N];
	int mid[M];
	for(int i = 0; i < n; i++){
		scanf("%d%d", &x[i], &y[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			mid[(x[i]+x[j])/2+N]++;
		}
	}
	int max = 0;
	for(int i = 1; i < M; i++)
		if(mid[max] < mid[i]) max = i;
}
