#include<stdio.h>
float result_real,result_imag;
void complex_prod(float real1,float imag1,float real2,float imag2){
	result_imag=real1*imag2+imag1*real2;
	result_real=real1*real2-imag1*imag2;
} 
void complex_add(float real1,float imag1,float real2,float imag2){
	result_real=real1+real2;
	result_imag=imag1+imag2;
}
int main()
{
	float real1,real2,imag1,imag2;
	scanf("%f%f",&real1,&imag1);
	scanf("%f%f",&real2,&imag2);
	complex_add(real1,imag1,real2,imag2);
	printf("complex_add=%.0f+%.0fi\n",result_real,result_imag);
	complex_prod(real1,imag1,real2,imag2);
	printf("complex_prod=%.0f+%.0fi",result_real,result_imag);
}
