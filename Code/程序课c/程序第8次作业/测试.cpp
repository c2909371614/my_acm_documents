#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	struct local_time{
		int year,month,day,hour,minute,second;
	};
	struct local_time times,*p;
	time_t tms=time(NULL);
	;
	printf("%ld ",tms/(3600*24*365));
}
