#include <bits/stdc++.h>
typedef long long lld;
using namespace std;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int n; lld a[MAXN];
class Read_data {
	public:
		Read_data() {
			freopen("in.in","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
			freopen("ac.out","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
		}
		~Read_data(){
			fclose(stdin);//关闭文件
			fclose(stdout);//关闭文件
		} 
};
Read_data R;
int main()
{
	
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a+n);
//	for(int i = 0; i < n; i++)
//		cout << a[i] << " ";
//	cout << endl;
    lld ans = 1;
    for (int i = 0, j; i < n; i = j)
        for (j = i+1; j < n && a[j] < a[i]+j-i; j++)
            ans = ans * (a[i]+j-i-a[j]+1) % MOD;
    printf("%lld\n", ans);
    return 0;
}
