#include <bits/stdc++.h>
typedef long long lld;
using namespace std;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int n; lld a[MAXN];
class Read_data {
	public:
		Read_data() {
			freopen("in.in","r",stdin); //�����ض����������ݽ���in.txt�ļ��ж�ȡ
			freopen("ac.out","w",stdout); //����ض���������ݽ�������out.txt�ļ���
		}
		~Read_data(){
			fclose(stdin);//�ر��ļ�
			fclose(stdout);//�ر��ļ�
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
