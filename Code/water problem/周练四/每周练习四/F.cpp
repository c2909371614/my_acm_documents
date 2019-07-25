/*思路：从最后一个向前递推 
当第n个是O时，那么第n-1个不能为O，此种情况有f(n-2) * 2个 
当第n个为非O时，有f(n-1) * 2个； 
综上得递推公式：f(n)=f(n-2) * 2+f(n-1) * 2*/
#include <stdio.h>
int main()
{
    long long a[45];
    int n;
    a[1]=3; a[2]=8;
    for(int i = 3; i < 45; i++)
    {
        a[i] = 2*(a[i-1]+a[i-2]);
    }
  	while(~scanf("%d",&n))
    	printf("%I64d\n",a[n]);
    return 0;
}

