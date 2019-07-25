#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int MAX = 1e5 + 5;
string a, b;
string a_temp, a_sub;
bool cmp(char a, char b)
{
	return a > b;
}
int main()
{
	cin >> a >> b;
	int len = a.size();
	sort(a.begin(), a.end(), cmp);
	if(a.size() < b.size() || a < b)
	{
		cout << a << endl;
		return 0;
	}
	else {
		for(int i = 0; i < len; i++)
		{
			for(int j = i; j < len; j++)
			{
				a_temp = a.substr(0, i) + a[j] + a.substr(i, j-i) + a.substr(j+1);
				a_sub = a.substr(i, j-i) + a.substr(j+1);
				reverse(a_sub.begin(), a_sub.end());
//				cout << "a_t:" << a_temp  << endl;
//				cout << "a:" << a.substr(0, i) + a[j] + a_sub << endl;
				if(a_temp <= b){//最大的都不超过b 
					a = a_temp;
					cout << a <<endl;//直接输出 
					return 0;
				}
				else if(a.substr(0, i) + a[j] + a_sub <= b){
					//cout << "a:" << a.substr(0, i) + a[j] + a.substr(i, j-i) + a_sub << endl;
					a = a_temp;//最小的小于b这个数便可取
					break; 
				} 
			//	cout << " " << a << endl;		 
			}
		}
		cout << a << endl; 
	}	
}
