#include<bits/stdc++.h>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e5 + 5;
struct node {
	long long pos, num;//λ�ú;�ס���� 
} a[MAX];

long long n, s, ans = 0;

bool cmp(node x, node y) {
	return (x.pos < y.pos);
}

int main() {
	FAST_IO;
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i].pos >> a[i].num;
	sort(a + 1, a + n + 1, cmp);//����λ�ô�С�������� 
	ll left = 1, right = n;//�������ұ߽� 
	while (left <= right) {
		if (a[right].pos <= s) {//ȫ��������� 
			ans += (s - a[left].pos);
			break;
		}
		if (a[left].pos >= s) {//ȫ�������ұ� 
			ans += (a[right].pos - s);
			break;
		}
		ans += (a[right].pos - a[left].pos);//���һ����·�� 
		
		/*����ϵ��ˣ�������С��һ�߷�����Ͷ����һ�ߣ�
		�ʶ����������������������ұߵ��������������
		��������ans += ���߼�·�� */ 
		if (a[left].num >= a[right].num) { 
			while (left < right && a[left].num >= a[right].num)
				a[left].num += a[right--].num;
		} 
		else {
			while (left < right && a[right].num > a[left].num)
				a[right].num += a[left++].num;
		}
	}
	cout << ans << endl;
	return 0;
}

