#include"stdio.h"
int h=0;
void move(char a,char c,int n) {
	printf("��%d��:��%d���̴�%c������%c\n",++h,n,a,c);
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
	printf("3 ������Ϊx��y��z��Բ�������x ��������y ���Ƶ�z ����������Բ������");
	scanf("%d",&n);
	fuct(n,'x','y','z');
}


