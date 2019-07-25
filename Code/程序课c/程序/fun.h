#include<stdio.h>

struct students{
	int num;
	char name[10];
	int computer,English,math;
	double average;
};

int update_score(struct students *p,int n,int num,int course,int score)//score update function
{
	int i,pos;
	for(i=0;i<n;i++,p++)
		if(p->num==num)break;
	if(i<n){
		switch(course){
			case 1:p->math=score;break;
			case 2:p->English=score;break;
			case 3:p->computer=score;break;
		}
		pos=i;//i will add one more
	}
	else pos=-1;
	return pos;
}
