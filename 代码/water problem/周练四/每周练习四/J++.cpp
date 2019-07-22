/*�ܶ���ֺ�������ֱ�ӵ��ã������ĺܷ��㣬����ʹ�ÿ���ȥ�ο����ϵĲ���Ŷ*/ 
#include <iostream>
#include <algorithm>
using namespace std;
const int Max = 100005;
int n;
int a[Max], b[Max], c[Max];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i = 0; i < n; i++) scanf("%d",&a[i]);
		for(int i = 0; i < n; i++) scanf("%d",&b[i]);
		for(int i = 0; i < n; i++) scanf("%d",&c[i]);	
		long long ans = 0;
		sort(a,a+n);sort(c,c+n,cmp);
		for(int i = 0; i < n; i++)
		{
			//cout << lower_bound(a,a+n,b[i]) - a << " " << lower_bound(c,c+n,b[i],greater<int>()) - c << endl;
			ans = ans + (long long)(lower_bound(a,a+n,b[i]) - a) * (lower_bound(c,c+n,b[i],greater<int>()) - c);
		}
		cout << ans << endl; 
	}
	return 0;
 } 
