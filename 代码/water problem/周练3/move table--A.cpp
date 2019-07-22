#include<stdio.h>
int main()
{
	int T,N,room1[10005],room2[10005],times;
	scanf("%d",&T);
	for(int j=1;j<=T;j++){
		//times=10;
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
			scanf("%d%d",&room1[i],&room2[i]);
			if(room1[1]==room2[1])times=0;
			else times=10;
		for(int i=2;i<=N;i++){
			if(room1[i]==room2[i]);
			else if(room1[i]>=room2[i-1]&&room1[i]<=room1[i-1])times+=10;
			else if(room1[i]>=room1[i-1]&&room1[i]<=room2[i-1])times+=10;
			else if(room2[i]>=room2[i-1]&&room2[i]<=room1[i-1])times+=10;
			else if(room2[i]>=room1[i-1]&&room2[i]<=room2[i-1])times+=10;
		}
	printf("%d\n",times);	
	}
	return 0;
 } 
