#include"stdio.h"
int h=0;
void move(char a,char c,int n) {
	printf("第%d步:将%d号盘从%c上移至%c\n",++h,n,a,c);
}
void fuct(int n,char a,char b,char c) {
	if(n==1)
		move(a,c,1);
	else {
		fuct(n-1,a,c,b);
		move(a,n,c);
		fuct(n-1,b,a,c);
	}
}
int main() {
	int n;
	printf("3 个塔座为x、y、z，圆盘最初在x 座，借助y 座移到z 座。请输入圆盘数：");
	scanf("%d",&n);
	fuct(n,'x','y','z');
}


