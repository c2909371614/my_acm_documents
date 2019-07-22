#include<stdio.h>
double fact(int n);
int main(void)
{
    int n,m,result;
    printf("enter n m:");
    scanf("%d %d",&n,&m);
    result=fact(n)/(fact(m)*fact(n-m));
    printf("%d",result);

}
double fact(int n) {
    int i;
    double product;
    product=1;
    for(i=1;i<=n;i++){
    product=product*i;
    }
    return product;
}

