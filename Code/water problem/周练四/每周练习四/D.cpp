/*站在第n个蜂房想一下，前一步是从哪里来的，问题就清楚了。
由于蜜蜂每次只能从前1个蜂房前2个蜂房过来，那么f(n)=f(n-2)+f(n-1)。这部就是一个菲波拉契数列吗？就是一个递推问题？
可是，开始时候，蜜蜂是在第1个蜂房，所以数列的开始几项会有所不同。
f(1)=0，因为蜜蜂开始在第1个蜂房；
f(2)=1，蜜蜂只能从第1个蜂房来到第2个蜂房；
f(3)=2，蜜蜂可以从第1个蜂房过来，也可以从第2个蜂房过来；
f(n)=f(n-2)+f(n-1)，n>3。
有了以上的递推式，一切几乎就解决了。*/

/* HDU2044 一只小蜜蜂... */
 
#include <iostream>
#define MAXN 50
 
typedef long long LL;
 
LL fn[MAXN+1];
 
void setfn()
{
    int i;
 
    fn[0] = 0;
    fn[1] = 0;
    fn[2] = 1;
    fn[3] = 2;
    for(i=4; i<=MAXN; i++)
        fn[i] = fn[i-2] + fn[i-1];
}
 
int main()
{
    int n, a, b;
 
    // 先打表（以防万一测试集合大）
    setfn();
 
    scanf("%d", &n);
    while(n--) {
        // 读入a和b
        scanf("%d%d", &a, &b);
 
        // 输出结果
        printf("%lld\n", fn[b - a + 1]);
    }
 
    return 0;
}
