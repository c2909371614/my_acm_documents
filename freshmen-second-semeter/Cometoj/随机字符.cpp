#include<bits/stdc++.h>
using namespace std;
int Rand(int n)
{
	return rand() * rand() % n + 1;
}
int main()
{
	fstream out("in.in", ios::out);
	srand(time(0));
	int n = Rand(50); 
	out << n << endl;
	for(int i = 0; i < n; i++)
		out << Rand(50) << " ";
	out << endl;
	out.close(); 
 } 
