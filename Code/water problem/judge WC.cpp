#include<stdio.h>
int judge_wc(int n){
	 int n1,bug=0;
	 while(n){
	 	n1=n%10;
	 	if(n1!=4&&n1!=7)bug++;
	 	n=n/10;
	 }
	 if(!bug)return 1;
	 else return 0;
}
int main()
{
	int n,factor,bug=0;
	scanf("%d",&n);
	for(factor=1;factor<=n;factor++)
	
		if(n%factor==0){bug=judge_wc(factor)+bug;/*printf("%d ",factor);*/}
	if(bug)printf("YES\n");
	else printf("NO\n");
	
	return 0;
}
