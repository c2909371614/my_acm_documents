#include<stdio.h>
#include<math.h>
int main()
{
	int n,r;
	while(scanf("%d%d",&n,&r)!=EOF){
		int pro=0,yu,i=0;
		int a[105];
		while(n){
			i++;
			a[i]=n%r;
			n/=r;
		}
		int flag=i;
		for(;i>0;i--){
			if(a[i]<0&&i==flag)printf("-");
			if(a[i]<0)a[i]=-a[i];
			if(a[i]>=10)switch(a[i]){
				case 10:printf("A");break;case 11:printf("B");break;
				case 12:printf("C");break;case 13:printf("D");break;
				case 14:printf("E");break;case 15:printf("F");break;
				}
			else printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0;			
}
 
