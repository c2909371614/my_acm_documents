#include<stdio.h>
#include<math.h>

double loop(double a)//������ʽ x��ȡ�κ�ֵ���Ų��ϵ�����Խ���ƽ� 
{					//��ʵֵ
	double x1=1.1,x2=1;
	while(fabs(x1-x2)>0.00001){
		x1=x2;
		x2=(2*pow(x1,3)+a)/(3*pow(x1,2)); 
	}	
 
	return x2;
}
int main() 
{
	double a;
	scanf("%lf",&a);
	if(a)printf("%.6f",loop(a));
	else printf("a=0");
	return 0;
 } 
