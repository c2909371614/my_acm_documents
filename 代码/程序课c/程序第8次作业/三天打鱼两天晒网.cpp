/*��3��	�׻�˵"������㣬����ɹ��"��ĳ�˴ӽ����һ�쿪ʼ��������������
int Result(struct Date )����0��ʾ���ڷǷ���1��ʾ���㣬2��ʾɹ����ʵ�ֲ�����֮*/ 
#include<stdio.h>
struct date{
	int year,month1,day;
};
int result(struct date date1)
{
	int days=date1.day;
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(date1.year%4==0&&date1.year%100!=0||date1.year%400==0)
		month[2]++;
	if(date1.day>month[date1.month1])
		return 0;
	while(date1.month1--)
		days+=month[date1.month1];
	switch(days%5){
		case 1:case 2:case 3:return 1;
		case 4:case 0:return 2;
	}
}
int main()
{
	struct date date1;
	puts("enter date:");
	scanf("%d%d%d",&date1.year,&date1.month1,&date1.day) ;
	puts("0��ʾ���ڷǷ���1��ʾ���㣬2��ʾɹ��");
	printf("%d\n",result(date1));
	return 0;
}
