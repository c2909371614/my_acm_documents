#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	double rate[10] = {0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};
	double b[10] = {0, 1500, 4500, 9000, 35000, 55000, 80000};
	double a[10] = {0, 45, 300, 900, 6500, 6000, 8750};
	for(int i=1; i<=6; i++) a[i] += a[i-1];
	double m, ans;
	while(scanf("%lf", &m) != EOF) {
		for(int i = 6; i>=0; i--) {
			if(m > a[i]) {
				ans = b[i] + (m - a[i]) / rate[i];
				break;
			}
		}
		printf("%d\n", (int)(ans ) + 3500);
	}
	return 0;
}

