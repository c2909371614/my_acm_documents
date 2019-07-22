#include <stdio.h>
#include <stdlib.h>
#include"fun.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int course,i,n,num,pos,score;
	struct students ss[50];
	puts("enter n:");//reminder enter n 
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Input the information No.%d:\n",i+1);
		printf("num name math English computer score:\n");
		scanf("%d%s%d%d%d",&ss[i].num,ss[i].name,&ss[i].math,&ss[i].English,&ss[i].computer);
	} 
	printf("Input the number of the students to be updated:");
	scanf("%d",&num);
	puts("Choice the course:1.math 2.English 3.computer:");
	scanf("%d",&course);
	puts("Input the new score");
	scanf("%d",&score);
	
	pos=update_score(ss,n,num,course,score);
	if(pos==-1)
		printf("Not found!\n");
		else {
			puts("After update:");
			printf("num\t math\t English\t computer\n");
			printf("%d\t %d\t %d\t %d\n",ss[pos].num,ss[pos].math,ss[pos].English,ss[pos].computer);
		}
		return 0;
}

