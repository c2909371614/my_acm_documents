#include<stdio.h>
#include<string.h> 
#include<ctype.h>
#include<math.h>
void strcat_(char a[],char b[])//Ϊ����⺯�������ӡ������»��� 
{
	int n,len=strlen(b);
	for(n=0;a[n]!=0;n++);
	for(int i=n,j=0;i<len+n&&j<len;i++,j++)
		a[i]=b[j];
	a[len+n]='\0';
}
int strlen_(char a[])
{
	int n;
	for(n=0;a[n]!=0;n++);
	return n;//���ȼ�����\0��=0�� 
 } 
void strlwr_(char a[])
{
	int i=0;
	while(a[i]){
	 	a[i]=tolower(a[i++]);//printf("%c",a[i]);
	 }
}
int strcmp_(char c[],char d[])
{
	int i=0;
	bool flag=false;
	for(;c[i]!=0||d[i]!=0;i++)
		if(c[i]!=d[i]) return c[i]-d[i];
		//sum+=fabs(c[i]-d[i]);
	//printf("c.len=%d d.len=%d\n",strlen(c),strlen(d)) ;
	return 0;	
}
int main()
{
	char a[100],b[20];
	puts("enter strings a and b:");
	gets(a);
	gets(b);
	strcat_(a,b);//strcat()���� 
	puts(a);//puts(b);
	printf("lenth=%d\n",strlen_(a));//strlen()���� 
	strlwr_(a);puts(a);//strlwr()����
	char c[100],d[50];
	gets(c);gets(d);
	if(!strcmp_(c,d)) printf("c=d");
	else printf("fabs(c-d)=%d\n",strcmp(c,d));//strcmp()����
	
	
	return 0; 
}
 
