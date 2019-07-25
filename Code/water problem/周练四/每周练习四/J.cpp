/*����˼·����ͦ����ģ�����ѡ��b[i]Ϊ����,Ȼ��ȥa[]�ұ�b[i]С�ĸ��� ���� c[]�б�b[i]��ĸ���
������ôѰ�ҵ�Ȼ����ֱ�ӱ����ˣ�O(n*n)�ĸ��Ӷ��ǲ��еģ��Ǿ��ö��֡� �ԣ����Ƕ��֣���������һ��ʼ��д����
Ȼ��WA, һֱ���ɶ���д���ˣ������˺þ÷���û���⡣�����ŷ�����n*n ������long long!!! ---- By Jline*/
#include <iostream>
#include <algorithm>
using namespace std;
const int Max = 100005;
int n;
int a[Max], b[Max], c[Max];
int f1(int key)
{
	int l = 0, r = n-1, mid, K = -1;
	while(l <= r)
	{
		mid = (l + r) >> 1;
	//	cout << a[mid] << endl;
		if(a[mid] < key){
			K = mid;
			l = mid+1;
		}
		else r = mid - 1;
	}
	//cout << "K is " << K+1 << endl;
	return K+1 ;
}
int f2(int key)
{
	int l = 0, r = n, mid, K = n;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(c[mid] > key){
			K = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	//cout << "K is " << n-K << endl;
	return n - K;
}


int main()
{
	while(~scanf("%d",&n))
	{
		for(int i = 0; i < n; i++) scanf("%d",&a[i]);
		for(int i = 0; i < n; i++) scanf("%d",&b[i]);
		for(int i = 0; i < n; i++) scanf("%d",&c[i]);	
		long long ans = 0;
		sort(a,a+n);sort(c,c+n);
		for(int i = 0; i < n; i++)
		{
			//cout << f1(b[i]) << " " << f2(b[i]) << endl; 
			ans += (long long)f1(b[i])*f2(b[i]);
		}
		cout << ans << endl; 
	}
	return 0;
 } 
