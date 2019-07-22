/*答案=总数-不符合要求的数, 简单数学题, 记得处理左端点*/

#include <iostream>
using namespace std;

int t, x, y, l, r;
int main()
{
	cin >> t; 
	while(t--)
	{
		cin >> x >> y >> l >> r;
		l--;
		cout << x/y -((r/y)-(l/y)) <<endl;
	}
	return 0;
 } 
