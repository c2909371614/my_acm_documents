#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,s1[1000],s2[1000],dp[1000]={0},maxxx=-1;
        scanf("%d",&a);
        for(int i=1;i<=a;i++)
            scanf("%d",&s1[i]);
        scanf("%d",&b);
        for(int i=1;i<=b;i++)
            scanf("%d",&s2[i]);
        for(int i=1;i<=a;i++)
        {
            int maxx=0;
            for(int j=1;j<=b;j++)
            {
            	//printf("s1[%d]=%d-s2[%d]=%d:dp[%d]=%d maxx=%d maxxx=%d\n "
//						,i,s1[i],j,s2[j],j,dp[j],maxx,maxxx);
                if(s1[i]==s2[j])
                    dp[j]=maxx+1;
                if(s1[i]>s2[j])
                {
                    maxx=max(maxx,dp[j]);
                }
                maxxx=max(maxxx,dp[j]);
//                printf("ÅÐ¶Ïºó:dp[%d]=%d maxx=%d maxxx=%d\n\n",j,dp[j],maxx,maxxx);
            }
        }
        printf("%d\n",maxxx);
        if(t)
            printf("\n");
    }
    return 0;
}
