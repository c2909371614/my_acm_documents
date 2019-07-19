#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e5 + 5;
int DP[20][2][2][14];/*记录DP[pos][a][b][j]
pos表示位置a表示状态b表示前面是否有13
下满足条件的个数  
DP[pos][状态]记录某一特征下的值 */
int num[20];//拆数字
void init()
{
	memset(DP, -1, sizeof(DP));//初始化为0 
//	cout<<DP[19][1][1][1]<<endl; 
 } 
int dfs(int pos, int state, int ok, int remain, int limit)
{
	if(pos == -1 )return remain==0&&ok?1:0;//到个位算一个计数需要整除13 
	if(!limit && DP[pos][state][ok][remain] != -1)
		return DP[pos][state][ok][remain];//该状态已经记录 
	int up = limit?num[pos]:9;//限制该位的最大数
	int ans = 0;
	for(int i = 0; i <= up; i++)
	{
		ans += dfs(pos - 1, i == 1, ok || (state&&i==3), (remain*10+i)%13, limit && i==up);//状态记录 		
	}
	if(!limit)DP[pos][state][ok][remain] = ans;
	/*到达限制时状态与未达到限制时不同，不能记录*/ 
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
