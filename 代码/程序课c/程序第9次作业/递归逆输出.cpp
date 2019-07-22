#include<stdio.h>
int reverse(unsigned long n) {
	if(n%10!=0)	{
		printf("%d",n%10);
		reverse(n/10);
	}
	else
		return 0;
}
int main() {
	unsigned long n;
	scanf("%d",&n);
	reverse(n);
	return 0;
}
