#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e5 + 5;
int DP[20][2][2][14];/*��¼DP[pos][a][b][j]
pos��ʾλ��a��ʾ״̬b��ʾǰ���Ƿ���13
�����������ĸ���  
DP[pos][״̬]��¼ĳһ�����µ�ֵ */
int num[20];//������
void init()
{
	memset(DP, -1, sizeof(DP));//��ʼ��Ϊ0 
//	cout<<DP[19][1][1][1]<<endl; 
 } 
int dfs(int pos, int state, int ok, int remain, int limit)
{
	if(pos == -1 )return remain==0&&ok?1:0;//����λ��һ��������Ҫ����13 
	if(!limit && DP[pos][state][ok][remain] != -1)
		return DP[pos][state][ok][remain];//��״̬�Ѿ���¼ 
	int up = limit?num[pos]:9;//���Ƹ�λ�������
	int ans = 0;
	for(int i = 0; i <= up; i++)
	{
		ans += dfs(pos - 1, i == 1, ok || (state&&i==3), (remain*10+i)%13, limit && i==up);//״̬��¼ 		
	}
	if(!limit)DP[pos][state][ok][remain] = ans;
	/*��������ʱ״̬��δ�ﵽ����ʱ��ͬ�����ܼ�¼*/ 
	return ans; 
 }
int select(ll x)
{
	int i = 0;
	while(x)
	{
		num[i++] = x % 10;
		x /= 10;
	}
	return dfs(i-1, 0, 0, 0, 1);
 } 
 int main()
{
	ll n;
	
	while(~scanf("%lld",&n))
	{
		init();
		printf("%d\n", select(n));
	}
 } 
