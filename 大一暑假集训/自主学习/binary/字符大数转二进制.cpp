
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
struct Bin {
	int data[MAX];
	int size;
	Bin(string s)
	{
		size = 0;
		int len = s.size();
		int temp[MAX];
		for (int i = 0; i < len; i++)
			temp[i] = s[i] - '0';
		int flag = 1;
		while (flag) {
			flag = 0;
			for (int i = 0; i < len; i++) {
				if (temp[i] == 0)continue;//减少不必要的操作
				int val = temp[i] / 2;
				flag += val;
				if (i == len - 1)data[size++] = temp[i] % 2;
				else temp[i + 1] += (temp[i] % 2) * 10;
				temp[i] = val;
			
			}
		}
		
	}
	void print()const {
		for (int i = 0; i < size; i++)
			cout << data[size-i-1];
		cout << endl;
	}
	int Q_power(int a, int b, int mod) {
		a %= mod;
		b %= mod;
		int ans = 1 % mod;
		while (b) {
			if (b & 1)ans = ans * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
	}

};
void display_bin(int a)
{
	if (a != 1 && a != 0) {
		display_bin(a / 2);
		cout << a % 2;
		return;
	}
	else cout << a;
}
int main()
{
	Bin a("10");
	a.print();
	return 0;
}