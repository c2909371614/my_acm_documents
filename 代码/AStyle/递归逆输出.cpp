#include<stdio.h>
int reverse(unsigned long n) {
	//123->3->3*10+2->32*10+1->321

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
