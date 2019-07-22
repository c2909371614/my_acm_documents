//1500£∫45 4500£∫300 9000£∫900 35000£∫6500 55000£∫6000
//80000£∫8750 “‘…œ£∫0.45*(tax-45-300-900-6500-6000-8750)
#include<stdio.h>
int main()
{
	double M,mon;
	scanf("%lf",&M);
		if(M>22495){
			mon=83500+(M-22495)/0.45;
			printf("%.0f",(int)(mon+0.5));
		}
			else if(M>13745){
			mon=58500+(M-13745)/0.35;
			printf("%.0f",(int)(mon+0.5));
			
		}
		else if(M>7745){
			mon=38500+(M-7745)/0.3;
			printf("%d",(int)(mon+0.5));
		}
		else if(M>1245){
			mon=12500+(M-1245)/0.25;
			printf("%d",(int)(mon+0.5));
		}
		else if(M>345){
			mon=8000+(M-345)/0.2;
			printf("%d",(int)(mon*100+0.5));
		}
		else if(M>45){
			mon=5000+(M-45)/0.1;
			printf("%d",(int)(mon+0.5));
		}
		else if(M>0){
			mon=3500+M/0.03;
			printf("%d",(int)(mon+0.5));
		}
	return 0;
}
