#include <iostream>
using namespace std;

int main()
{
	int t, n, k;
	long long a[100005], sum[100005];
	cin >> t;
	while(t--)
	{
		a[0] = 0, sum[0] = 0;
		cin >> n ;
		for(int i = 1; i <= 2*n; i++)
		{
			cin >> a[i];
			sum[i] = sum[i-1] + a[i];
		}
		for(int i = 1; i < n; i++)
		{
			cout << sum[i*2] - sum[i-1] << " ";
		}
		cout << sum[n*2] - sum[n-1] << endl;
	}
}
