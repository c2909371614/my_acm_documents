/*˼·�������һ����ǰ���� 
����n����Oʱ����ô��n-1������ΪO�����������f(n-2) * 2�� 
����n��Ϊ��Oʱ����f(n-1) * 2���� 
���ϵõ��ƹ�ʽ��f(n)=f(n-2) * 2+f(n-1) * 2*/
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

