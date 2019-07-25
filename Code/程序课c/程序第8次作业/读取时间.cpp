#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct local_time{
	int year,month,day,hour,minute,second;
};
int get_month(int *day,int year){
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int i=1;
	if(year%4==0&&year%100!=0||year%400==0)
		month[2]++;
	while(*day>month[i]){
		*day-=month[i];
		i++;
	}
	return i;
}
int get_year(int *day){
	int year=1970,years[2]={365,366};
	int leap=0;
	while(*day>years[leap]){
		year++;
		leap=year%4==0&&year%100!=0||year%400==0;
		*day-=years[leap];
	}
	return year;
}
void turn_time(struct local_time *p,time_t tms){
	p->day=tms/(24*3600)+1;
	p->year=get_year(&(p->day));
	p->hour=(tms-tms/(3600*24)*3600*24)/3600;
	p->minute=(tms-tms/3600*3600)/60;
	p->second=tms-tms/60*60;
	p->month=get_month(&(p->day),p->year);
}
int main()
{
	
	struct local_time times;
	time_t tms=time(&tms);
	turn_time(&times,tms);
	int i;
	printf("%d.%d.%d  %d:%d:%d\n",times.year,times.month,times.day,times.hour+8,times.minute,times.second);
	getchar();
}
