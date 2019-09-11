#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll a[MAX];
bool cmp(ll a, ll b){
	return a < b;
}
class Read_data {
	public:
		Read_data() {
			freopen("in.in","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
			freopen("my.out","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
		}
		~Read_data(){
			fclose(stdin);//关闭文件
			fclose(stdout);//关闭文件
		} 
};
Read_data R;
int main()
{
	
	ll n;
	cin >> n;
	ll ans = 1;
	ll sum = 1;
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	ll count = 1;
	sort(a, a+n, cmp);
//	for(int i = 0; i < n; i++)
//		cout << a[i] << " ";
//	cout << endl;
	ll temp;
	ll flag =  0;
	for(ll i = 1; i < n; i++){
		if(a[i] == a[i-1]){
			if(!flag)flag = a[i]; 
			ans *= count + flag - a[i] + 1;
			count++;
		}
		else if(count + flag - a[i] > 0){ 
			ans *= count + flag - a[i] + 1;
			count++;
		} 
		else {
			sum *= ans;
			sum %= MOD; 
			temp = ans;
			ans = 1;
			count = 1;
			flag = 0; 
		}
		ans %= MOD; 
//		cout << " " << ans << " count " << count << endl;
	}
	sum *= ans;
	cout << sum%MOD << endl;
 } 
