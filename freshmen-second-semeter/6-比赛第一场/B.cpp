#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
#define LL long long
long long  gcd(long long  a, long long  b) { return a == 0 ? b : gcd(b % a, a); }
 
 
int Q, num, cur;
char type;
stack<int>a, b;
int dp[1000005], ans[1000005];
int main()
{
	while (~scanf("%d", &Q))
	{
		getchar();
		cur = 1;
		dp[0] = 0;
		ans[0] = -INF;
		while (!a.empty())a.pop();
		while (!b.empty())b.pop();
		while (Q--)
		{
			scanf("%c", &type);
			if (type == 'I')
			{
				scanf("%d", &num);
				getchar();
				dp[cur] = dp[cur - 1] + num;
				ans[cur] = max(dp[cur], ans[cur - 1]);
				cur++;
				a.push(num);
			}
			else if (type == 'D')
			{
				getchar();
				cur--;
				a.pop();
			}
			else if (type == 'L')
			{
				getchar();
				if (!a.empty())
				{
					int t = a.top();
					a.pop();
					cur--;
					b.push(t);
				}
			}
			else if (type == 'R')
			{
				getchar();
				if (!b.empty())
				{
					int t = b.top();
					b.pop();
					dp[cur] = dp[cur - 1] + t;
					ans[cur] = max(dp[cur], ans[cur - 1]);
					cur++;
					a.push(t);
				}
			}
			else if (type == 'Q')
			{
				scanf("%d", &num);
				getchar();
				printf("%d\n", ans[num]);
			}
		}
	}
	getchar();
	getchar();
}
