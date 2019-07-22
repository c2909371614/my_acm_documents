#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int num;
	struct node *next;
};
struct node*head=NULL;
void insert(){
	struct node *ptr;
	struct node *stu;//ÓÃÓÚÊäÈë£»
	stu=(struct node*)malloc(sizeof(struct node));
	puts("enter num:");
	scanf("%d",&stu->num );
	//ptr=stu;
	if(head==NULL){
		head=ptr;
		head->next=NULL; 
		return;
	}
	ptr=head;	
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=stu;
	stu->next=NULL;
	return;
}
int creat(){
	insert();
}
int main()
{
	int chioce;
	do{
		puts("enter your chioce(1:creat 2:insert 0:exit):");
		scanf("%d",&chioce);
		switch(chioce){
			case 1:creat();break;
			case 2:insert();break;
			default:puts("error input");
		}
	}while(chioce!=0);
}
