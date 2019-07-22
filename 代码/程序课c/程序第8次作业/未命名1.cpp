#include<stdio.h>
int main()
{
	double fahr,c,upper,lower;
	printf("enter lower and upper:");
	scanf("%lf%lf",&lower,&upper);
	printf("fahr celsius");
	for(fahr=lower;fahr<=upper;fahr++){
		c=5*(fahr-32)/9;
		printf("%.0f %6.1f\n",fahr,c);
	}
	return 0;
 } 
