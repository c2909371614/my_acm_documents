/*由上往下推，由于结果状态多，不好处理

由底往上推，都归于一个起点，只需要算出由底往上得到的最大价值即可

方程：dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+a[i][j];*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
int a[105][105],dp[105][105];
 
int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(i = 1;i<=n;i++)
        {
            for(j = 1;j<=i;j++)
            scanf("%d",&a[i][j]);
        }
        for(i = n;i>=1;i--)
        {
            for(j = 1;j<=i;j++)
            {
                dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
            }
        }
        printf("%d\n",dp[1][1]);
    }
    return 0;
} 
