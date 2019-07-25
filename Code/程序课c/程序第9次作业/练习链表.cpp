#include<stdio.h>
#include<stdlib.h>
struct list1{
	int num,age;
	char name[10];
	struct list1 *next;
};
struct list1 create_l();
struct list1 read_l(struct list1 *head);
int main()
{
	struct list *head;
	int choice;
	do{
		puts("1:create\t2:read\t0:exit");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				head=create_l();
			case 2:
				 
		}
	}
 } 
