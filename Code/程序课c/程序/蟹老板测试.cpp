#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu_node{
	int num;
	char a[20];
	int score;
	struct stu_node*next; 
}; 
struct stu_node*create_stu_doc();
struct stu_node*interdoc(struct stu_node*head,struct stu_node*stu);
struct stu_node*deletdoc(struct stu_node*head,int num);
void print_stu_node(struct stu_node*head);
int main()
{
	struct stu_node *head,*p;
	int choice,num,score;
	char a[20];
	int size=sizeof(struct stu_node);
	while(choice!=0){
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				head=create_stu_doc();
				break;
			case 2:
				printf("inter num name score \n");
				scanf("%d%s%d",&num,a,&score);
				p=(struct stu_node*)malloc(size);
				p->num=num;
				p->score=score;
				strcpy(p->a,a);
				head=interdoc(head,p);
				break;
			case 3:
				printf("inter num\n");
				scanf("%d",&num);
				head=deletdoc(head,num);
				break;
			case 4:
				print_stu_node(head);
				break;
			case 0:
				break; 
		}
	}
	//return 0;
}
struct stu_node*create_stu_doc()
{
	struct stu_node*head,*p;
	int num,score;
	char a[20];
	int size=sizeof(struct stu_node);
	head=0;
	printf("inter your num,score,name\n");
	scanf("%d%d%s",&num,&score,a);
	while(num!=0){
		p=(struct stu_node*)malloc(size);
		p->num;
		p->score;
		strcpy(p->a,a);
		head=interdoc(head,p);
		scanf("%d%d%s",&num,&score,a); 
	}
	return head;
}
struct stu_node*interdoc(struct stu_node*head,struct stu_node*stu){
	struct stu_node*ptr,*ptr1,*ptr2;
	ptr2=head;
	ptr=stu;
	if(head==0){
		head=ptr;
		head->next=0;
}
	else{
		while((ptr->num>ptr2->num)&&(ptr2->next!=0)){
			ptr1=ptr2;
			ptr2=ptr2->next;
		}
		if((ptr->num<ptr2->num)&&(ptr2->next!=0)){
			if(head==ptr2)
				head=ptr;
			else
				ptr1->next=ptr;
				ptr->next=ptr2;
		}
		else{
			ptr2->next=ptr;
			ptr->next=0;
		}
	}
	return head;
}

struct stu_node*deletdoc(struct stu_node*head,int num){
	struct stu_node*ptr1,*ptr2;
	while(head!=0&&head->num==num){
		ptr2=head;
		head=head->next;
		free(ptr2);
	}
	if(head==0)
		return 0;
	ptr1=head;
	ptr2=head->next;
	while(ptr2!=0){
		if(ptr2->num==num)
		{
			ptr1->next=ptr2->next;
			free(ptr2);
		}
		else
			ptr1=ptr2;
		ptr2=ptr1->next;
	}
	return head;
}

void print_stu_node(struct stu_node*head){
	struct stu_node*ptr;
	if(head==0){
		printf("\n no records\n");
		return;
	}
	for(ptr=head;ptr;ptr=ptr->next)
		printf("%d\t%d\t%s",ptr->num,ptr->score,ptr->a);
}

