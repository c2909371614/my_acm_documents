#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];

int main()
{
    int n, t, k;
    scanf("%d",&t);
    while(t--)
    {
        long long sum = 0;
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; ++i)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0; i<n; ++i)
        {
            int l = i+1;
            int r = n-1;
            while(l<=r)
            {
                int mid =(l+r)/2;
                if(a[mid]-a[i]>k)
                    r=mid-1;
                else
                    l=mid+1;
            }
            sum+=r-i;
        }
        printf("%lld\n",sum);
    }
    return 0;
}

