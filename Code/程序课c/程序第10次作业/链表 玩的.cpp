#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ss{
	int num,score;
	char name[20];
	struct ss *next;
};
struct ss* head=NULL;
int insert_s(){
	struct ss *stu;//当前预插入学生
	if((stu=(struct ss*)malloc(sizeof(struct ss)))==NULL){
		printf("malloc file\n");
		exit(0);
	}
	struct ss *ptr1,*ptr2=head,*ptr=stu;
	puts("enter num,score,name(num=0->stop input):");
	scanf("%d%d%s",&stu->num,&stu->score,stu->name);
	
	while(stu->num!=0){
		if(head==NULL){//create new link
			head=stu;//puts("ok");
			head->next=NULL;
		}
		else if(ptr->num<=head->num){//insert the head of link
			head=stu;
			head->next=ptr2;
		}
		else {
			while(ptr->num>ptr2->num &&ptr2->next!=NULL){//move behind
				ptr1=ptr2;
				ptr2=ptr2->next;
			}
			if(ptr->num>ptr2->num){//insert the nail of link
				ptr2->next=ptr;
			}
			else {//insert between ptr1 and ptr2
				ptr1->next=ptr;
				ptr->next=ptr2;
			} 
		}
		if((stu=(struct ss*)malloc(sizeof(struct ss)))==NULL){
			printf("malloc file\n");
			exit(0);
		}
		ptr=stu;//ptr indicate present struct
		ptr2=head;
		puts("enter num,score,name(num=0->stop input):");
		scanf("%d%d%s",&stu->num,&stu->score,stu->name);
	}
	return 0;
}
void creat_s(){
	insert_s();
}
int del_s(){
	int d_num;
	struct ss* del,*ptr1,*ptr2;
	if(head==NULL)
		return 0;
	printf("enter the num that you want to delete:");
	scanf("%d",&d_num);
	while(d_num==head->num){
		del=head;
		head=head->next ;
		free(del);
	}
	//delete from head behind
	ptr1=head;
	ptr2=head->next;
	while(ptr2!=NULL/*要删除的不为空*/){
		if(d_num==ptr2->num){
			ptr1->next=ptr2->next;
			free(ptr2);
		} 
		else{
			ptr1=ptr2;
			ptr2=ptr2->next;
		}
	} 
}
void print_s(){
	struct ss *read=head;
	puts("num\tscore\tname");
	while(read!=NULL){
		printf("%d\t%d\t%s\n",read->num,read->score,read->name);
		read=read->next;
	}
}
int main()
{
	int chioce;
	do{
		puts("enter your chioce (1 create 2 insert 3 delete 4 print 0 exit)");
		scanf("%d",&chioce);
		switch(chioce){
			case 1:creat_s();break;
			case 2:insert_s();break;
			case 3:del_s();break; 
			case 4:print_s();break;
		}
	}while(chioce);
	return 0;	
}
