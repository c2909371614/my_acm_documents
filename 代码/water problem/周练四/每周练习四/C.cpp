/* HDU2031 进制转换 */
 
#include <stdio.h>
#include <string.h>
 
#define N 32
char ans[N + 1];
 
void reverse(char s[], int len)
{
    int i,j;
    int c;
 
    for(i=(s[0]=='-'?1:0),j=len-1; i<j;i++,j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
 
void convert(int n, int r, char s[])
{
    int i = 0;
 
    // 处理负数
    if(n < 0) {
        s[i++] = '-';
        n = -n;
    }
 
    while(n) {
        s[i] = n % r;
        if(s[i] >= 10)
            s[i] += 'A' - 10;
        else
            s[i] += '0';
        n /= r;
        i++;
    }
    s[i] = '\0';
 
    reverse(s, i);
}
 
int main(void)
{
    int n, r;
 
    while(scanf("%d%d", &n, &r) != EOF) {
        convert(n, r, ans);
        printf("%s\n", ans);
    }
 
    return 0;
}
