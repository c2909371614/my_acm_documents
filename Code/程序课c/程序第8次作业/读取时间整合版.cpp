#include<stdio.h> 
#include<time.h>
#include<stdlib.h>
struct local_time{
	int year,month,day,hour,minute,second;
};
int get_month(int *day,int year){
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int i=1;
	if(year%4==0&&year%100!=0||year%400==0)month[2]++;
	while(*day>month[i]){
		*day-=month[i];
		i++;
	}
	return i;
}
void turn_time(struct local_time *p,time_t tms){
	p->year =tms/(3600*24*365);
	p->day=(tms-3600*24*365*p->year)/(24*3600);
	p->hour=(tms-tms/(3600*24)*3600*24)/3600;
	p->minute=(tms-tms/3600*3600)/60;
	p->second=tms-tms/60*60;
	p->month=get_month(&((*p).day),p->year);
}
void read_2()
{
	
	struct local_time times;
	time_t tms=time(NULL);
	turn_time(&times,tms);
	int i;
	for(i=1970;i<times.year+1970;i++)
		if(i%4==0&&i%100!=0||i%400==0)
			times.day--;
	printf("%d.%d.%d  %d:%d:%d\n",times.year+1970,times.month,times.day,times.hour,times.minute,times.second);
}
void read_1()
{
	time_t t;
	t=time(NULL);
	struct tm *p;//tm 是 time.h头文件中定义的一个结构体其中变量存在范围 
	p=localtime(&t);
	printf("%d.%d.%d %d:%d:%d\n",p->tm_year+1900,p->tm_mon+1,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
}
int main()
{
	int choice;
	printf("enter a digiter :\n");//输入数字为一的话调用函数版读取时间，输入为其他数字为普通版 
	while(1){
		scanf("%d",&choice);
		if(choice==1)read_1();
		else read_2();
	}
	return 0;
}
