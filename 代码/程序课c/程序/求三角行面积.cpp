#include<stdio.h>
#include<math.h>
int main(void)
{
    double x1,x2,x3,y1,y2,y3;
    double a,b,c;
    printf("enter three poiners:");
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
    a=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    b=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
    c=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
    if(a>fabs(b-c)&&a<b+c){
        double l,s,area;
        l=a+b+c;
        s=l/2;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        printf("l=%.2f ",l);
        printf("area=%.2f",area);
        
        }
        else printf("impossible");
        return 0; 
    }


