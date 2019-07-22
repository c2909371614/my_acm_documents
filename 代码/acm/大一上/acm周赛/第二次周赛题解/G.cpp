#include <stdio.h>
#include <iostream>
using namespace std;
 
int main()
{
    int n,m;
    while(scanf("%d%d",&n, &m)!=EOF)
    {
        printf("%d\n", m + n - 1);
        for(int i=1; i<=m; i++)
            printf("%d %d\n", 1, i);
        for(int j=2; j<=n; j++)
            printf("%d %d\n", j, m);
    }
    return 0;
}
