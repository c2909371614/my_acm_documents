#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false);
using namespace std;
const int N = 1e6 + 5;
class Read_data {
	public:
		Read_data() {
			freopen("data.in","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
			freopen("2.out","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
		}
		~Read_data() {
			fclose(stdin);//关闭文件
			fclose(stdout);//关闭文件
		}
}READ;
int main() {
		string s, s2, sub = "";
		int n, m;
		cin >> n >> m;
		cin >> s >> s2;
		bool flag = true;
		for(int j = 0; j < n ; j++) {
			sub = "";
			for(int i = j; i < n; i++) {
				if(sub + s.substr(i) > s2) {
					printf("%d\n", n - i + sub.size());
					flag = false;
					break;
				} else if(s[i] == s2[sub.size()]) {
					sub += s[i];
				}
			}
			if(!flag)break;
		}
		if(flag) printf("-1\n");
}


