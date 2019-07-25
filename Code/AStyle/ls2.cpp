#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
//NΪ���ʽ�ĳ���
#define N 105
using namespace std;
int equal(char a[],char b[],int l1,int l2);//�ж������߼����ʽ�Ƿ�ȼ�
int getnumber(char a[],int l);//��ȡ�����ĸ���
char cal(char a[],int l);//�����߼����ʽ��ֵ
int pri(char ch);//�жϷ��ŵ����ȼ�

char c[26];//������¼���ʽ�б����ĸ����Լ�����������
int main() {
	char ans1[N],ans2[N];
	int l1,l2;//�������ʽ�ĳ���
	printf("�����������߼����ʽ\n");
	while(scanf("%s%s",ans1,ans2)!=EOF) {
		l1=strlen(ans1);
		l2=strlen(ans2);
		if(equal(ans1,ans2,l1,l2))
			printf("Equivalent\n");
		else
			printf("Different\n");
	}
	return 0;
}
int equal(char a[],char b[],int l1,int l2) {
	int i,j;
	char zhi1,zhi2;
	char ctemp[26];//�ֱ�λa,b,c����ʱ����
	char atemp[N];
	char btemp[N];
	int x=0,y=0;//a,b���ʽ�еı�������
	int n;//����ȡֵ������
	int tempn,max;
	char list[26];//����ȡֵ��
	y=getnumber(b,l2);
	x=getnumber(a,l1);
//   printf("����������%d\n",x);
	max=x>y?x:y;//ȡ�������ʽ�б������Զ��Ϊ׼��
	n=pow(2.0,max);//��ȡȡֵ����������3��������2^3��
//   printf("ȡֵ������%d\n",n);
	while(n) {
		getnumber(a,l1);
		strcpy(ctemp,c);//��ԭ
		strcpy(atemp,a);//��ԭ

		tempn=n;

		for(i=x; i>=0; i--) { //Maxλ����ȡֵ��
			list[i]=tempn%2+'0';
			tempn/=2;

		}
		j=1;
		for(i=0; i<26; i++) { //����26λȡֵ��
			if(ctemp[i]!='0') {
				ctemp[i]=list[j++];
			}
		}
		for(i=0; i<l1; i++) { //��a���ʽ�еı�����Ϊ��Ӧ��ֵ������a��Ϊ0��b��Ϊ0
			if(atemp[i]>='a'&&atemp[i]<='z')
				atemp[i]=ctemp[atemp[i]-'a'];
		}

		strcpy(btemp,b);//��ԭ
		for(i=0; i<l2; i++) { //��b���ʽ�еı�����Ϊ��Ӧ��ֵ������a��Ϊ0��b��Ϊ0
			if(btemp[i]>='a'&&btemp[i]<='z')
				btemp[i]=ctemp[btemp[i]-'a'];
		}
		zhi1=cal(atemp,l1);//������
		zhi2=cal(btemp,l2);
		if(zhi1!=zhi2) { //�ж��������ʽֵ�Ƿ����
			return 0;
		}
		n--;
	}

	return 1;
}
int getnumber(char a[],int l) {

	int number=0;//�����ĸ���
	int i;
	memset(c,'0',sizeof(c));
	for(i=0; i<l; i++) {
		if(a[i]>='a'&&a[i]<='z') {
			c[a[i]-'a']+=1;
		}
	}
	for(i=0; i<26; i++) {
		if(c[i]!='0') {
			number++;
		}
	}
	return number;
}
char cal(char a[],int l) {
	int i;
	int top=0;
	int j=0;
	char stack[N];//����ջ������ʽתΪ����ʽ
	char fin[N];//ת����ĺ���ʽ
	char result[N];//������������ջ
	char ch;
	fin[0]='#';
	for(i=0; i<=l; i++) {
		switch(a[i]) {
			case '\0':
				while(top>0) {
					fin[++j]=stack[top--];
				}
				break;

			case '(':

				stack[++top]=a[i];
				break;

			case '|':
			case '^':
			case '&':
			case '~':
				while(pri(stack[top])>=pri(a[i])) {
					fin[++j]=stack[top--];
				}
				stack[++top]=a[i];
				break;

			case ')':
				while(stack[top]!='(') {
					fin[++j]=stack[top--];
				}
				top--;
				break;

			default:
				fin[++j]=a[i];
				break;
		}
	}
	fin[++j]='\0';
	for(int i=0; i<=j; i++) cout<<fin[i]<<" ";
	cout<<endl;
	top=0;
	for(i=1; i<j; i++) {
		if(fin[i]=='0'||fin[i]=='1') {
			result[top++]=fin[i];
		} else {
			switch(fin[i]) {
				case '~':
					ch=result[--top];
					result[top]=(ch=='1')?'0':'1';
					top++;
					break;
				case '&':
					ch=result[--top];
					result[top-1]=(ch=='1'&&result[top-1]=='1')?'1':'0';
					break;
				case '|':
					ch=result[--top];
					result[top-1]=(ch=='1'||result[top-1]=='1')?'1':'0';
					break;

				case '^':
					ch=result[--top];
					result[top-1]=(ch==result[top-1])?'0':'1';
					break;
				default:
					printf("error\n");
					break;
			}
		}
	}

	return result[0];
}
int pri(char ch) {
	int num;
	switch(ch) {
		case '~':
			num=4;
			break;
		case '&':
			num=3;
			break;
		case '^':
			num=2;
			break;
		case '|':
			num=1;
			break;
		default:
			num=0;
			break;
	}
	return num;
}

