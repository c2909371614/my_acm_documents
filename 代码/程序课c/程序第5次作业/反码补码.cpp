#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void print(int *p){
	for(int i=1;i<=16;i++){
		printf("%d",p[i]);
		if(i==8)printf(" ");//ԭ 
	} 
	puts("");
}
int main()
{
	while(true){
		int pro,rem;
		int n,i,dis[100],add[100],ori[100];
		for(i=1;i<=16;i++)
			dis[i]=add[i]=ori[i]=0;
		scanf("%d",&n);
		int bug=n;//������ 
		i=16;n=abs(n);
		while(n){
			dis[i]=add[i]=ori[i]=n%2;
			n/=2;
			i--;
		}
		if(bug<0){//������ 
			dis[1]=add[1]=ori[1]=1;//[1]Ϊ����λ 
			for(i=2;i<=16;i++)
				if(ori[i]!=0)add[i]=dis[i]=0;
				else add[i]=dis[i]=1;
			int count=16,Bw=1;
			while(count>1){
				add[count]=(dis[count]+Bw)%2;
				Bw=(dis[count]+Bw)/2;
				count--;	
			}	
		}
		printf("ori:");
		print(ori);
		printf("dis:");
		print(dis); 
		printf("add:");
		print(add); 
	}
	return 0;
 } 
