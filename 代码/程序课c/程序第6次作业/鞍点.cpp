#include<stdio.h>
int main()
{
	int i,j,k,m,n,max,min,maxj,b;
	int a[10][10];
	printf("��������n:");
	scanf("%d",&n);
	printf("��������m:");
	scanf("%d",&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
		for(i=0;i<n;i++){
			//max=a[i][0];
			max=0; 
			for(j=0;j<m;j++)
				if(a[i][j]>a[i][max])//ÿ�����Ϊa[i][max]; 
					max=j;
			for(j=0;j<n;j++){
				if(a[i][max]>a[j][max])break;
			}
			if(j>=n){
				printf("����Ϊa[%d][%d]=%d",i,max,a[i][max]);break;
			}
		}
		if(i>=n)printf("û�а���"); 
//  		for(k=0;k<n;k++)
//    	if(a[i][j]<=a[k][j])
//    		b=1;
//    		if(b) printf("%d�ǰ���\n",a[i][j]);
//			else printf("\n�����ް��㣡\n");
		
return 0;
}

