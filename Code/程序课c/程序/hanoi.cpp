#include"stdio.h"
int h=0;
void move(char a,char c,int n) ;//declared
int fuct(int n,char a,char b,char c);
int main() 
{
	int n;
	printf("3 ������Ϊx��y��z��Բ�������x ��������y ���Ƶ�z ����������Բ������");
	scanf("%d",&n);
	fuct(n,'x','y','z');//f(x);
}//f(x)=x^2;a=f(2); 
void move(char a,char c,int n)
 {
	printf("��%d��:��%d���̴�%c������%c\n",++h,n,a,c);
}//f(n)->f(n-1)
int fuct(int n,char a,char b,char c)//define
 {//
	if(n==1)
		move(a,c,1);
	else {
		fuct(n-1,a,c,b);//n-1�� 
		move(a,b,n);//�޸� 
		fuct(n-1,b,a,c);//�޸� 
	}
}


