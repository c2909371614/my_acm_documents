/*��=����-������Ҫ�����, ����ѧ��, �ǵô�����˵�*/

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
