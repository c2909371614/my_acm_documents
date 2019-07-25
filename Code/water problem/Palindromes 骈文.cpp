#include<stdio.h>
#include<string.h>
int main()
{
	char a[52];
	int i,n,j,bug;
	for(j=1;j<=100;j++){
		bug=1; 
		gets(a);n=strlen(a);
		for(i=0;i<n/2;i++)
			if(a[i]!=a[n-i-1]){
				bug=0;break;
				}
		if(!(a[i]>='A'&&a[i]<='Z'))return 0;
		if(strcmp(a,"STOP")==0)
			break;
		if(bug)printf("#%d: YES\n",j);
		else	printf("#%d: NO\n",j);		
	}
	
 } 
