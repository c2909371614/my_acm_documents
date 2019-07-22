#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int math;
	struct node *next;
};
struct node *head=NULL;
struct node *Create();
struct node *Insert();
void print();
int main()
{
	head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	int choice;
	do{
		puts("enter your chioce(1:Create 2:Insert 3:print 0:exit):");
		scanf("%d",&choice);
		switch(choice){
			case 1:Create();break;
			case 2:Insert();break;
			case 3:print();
			default:puts("error intput\n");
		}
	}while(choice!=0);
	free(head);
	return 0;		
 } 
struct node *Create(){
	Insert();
}
struct node *Insert(){
	struct node *ptr=head,*stu;
	stu=(struct node*)malloc(sizeof(struct node));
	puts("enter math:") ;
	scanf("%d",&stu->math);
	while(ptr->next!=NULL)//保证ptr为最后一个元素 
		ptr=ptr->next;
	ptr->next=stu;
	stu->next=NULL;
}
void print(){
	struct node *p=head->next;
	while(p!=NULL){
		printf("math=%d\n",p->math);
		p=p->next;
	}
	return;
}
