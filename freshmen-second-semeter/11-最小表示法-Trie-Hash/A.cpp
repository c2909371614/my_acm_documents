#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e5+5;
const int INF = 0x3f3f3f3f;

char least[MAX];
char s[MAX];
int n;
void get_Least()
{
	char ss[2*MAX];
	strcpy(ss, s);
	strcat(ss, s);
	n = strlen(s);
	int i = 0, j = 1, k = 0;
	while(i < n && j < n)
	{
		if(ss[i+k] == ss[j+k])
			k++;
		if(k == n)break;//×Ö·û´®ÄÚÑ­»· 
		if(ss[i+k] > ss[j+k]){
			i = i + k + 1;
			k = 0; 
			if(i == j)i++;
		}
		else if(ss[i+k] < ss[j+k]){
			j = j + k + 1;
			k = 0;
			if(j == i)j++;
		}
		
	}
	int index = min(i, j);
	//cout << index+1 << endl;
	for(int i = index; i < index + n; i++)
		cout << ss[i];
	cout << endl; 
}
int main()
{
	FAST_IO;
	int T;
	cin >> T;
	while(T--)
	{
		cin >> s;
		get_Least();
	}
	
 } 
