#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
struct student *Insert_s(struct student *head, struct student *stud);
struct student{
	int num;
	char name[20];
	int score;
	struct student *next;
};
using namespace std;
struct student *Create_s(){
	struct student *head,*p;
	int num,score;
	char name[20];
	int size=sizeof(struct student);
	
	head=NULL;
	puts("Tnput num name and score(num=0 stop intput)");
	scanf("%d%s%d",&num,name,&score);//input num;

	while(num!=0){
		p=(struct student*)malloc(size);//size=struct;
		p->num=num;
		strcpy(p->name ,name);
		p->score =score;//cout<<"ok\n";
		//cout<<p->name <<p->num <<p->score <<p<<endl;
		head=Insert_s(head,p);
		scanf("%d%s%d",&num,name,&score);
	}
	return head;
}
struct student *Insert_s(struct student *head, struct student *stud){
	struct student *ptr,*ptr1=NULL,*ptr2; 
	ptr2=head;//ָ��ǰ��ַ 
	ptr=stud;//ptrָ������� ��������¼���
	/*ԭ����Ϊ��ʱ*///cout<<"ok\n"<<head<<endl; 
	if(head==NULL){
		head=ptr;
		head->next =NULL;
	}
	else {
		while((ptr->num>ptr2/*head*/->num)&&(ptr2->next!=NULL)){
			ptr1=ptr2;//ptr1Ϊ����ָ�� 
			ptr2=ptr2->next;//ptr1 ptr2 ���� 
		}
		if(ptr->num <=ptr2->num ){//��1 ��2֮�����
			if(head==ptr2)// because ptr2->next==NULL;
				head=ptr;
			else 
				ptr1->next =ptr;

			ptr->next=ptr2; //������� 
		} 
		else {//ptr2->next==NULL;
			ptr2->next=ptr;
			ptr->next=NULL;
		}
	} 
	return head;	
}
struct student *Dele_s(struct student *head,int num){
	struct student *ptr1,*ptr2;
	while(head!=NULL&&head->num ==num){
		ptr2=head;
		head=head->next ;
		free(ptr2);//��free�ڴ�
	}
	if(head==NULL)
		return NULL;//����Ϊ��
	ptr1=head;
	ptr2=head->next;
	//�ӱ�ͷ����һ������������з���ɾ��Ҫ��Ľ��
	while(ptr2!=NULL/*Ҫɾ���Ĳ�Ϊβ*/){
		if(ptr2->num ==num){
			ptr1->next=ptr2->next ;
			free(ptr2); 
		}		
		else 
			ptr1=ptr2;//���� 
		ptr2=ptr1->next; //ptrָ��ptr1����һ������� 
	} 
	return head; 
}
void print_s(struct student *head){
	struct student *ptr;
	if(head==NULL){
		puts("\nNo Records");
		return ;
	}
	puts("\nThe Students��Records Are:");
	puts("Num\t Name\t Score");
	for(ptr=head;ptr!=NULL;ptr=ptr->next)
		printf("%d\t%s\t%d\n",ptr->num ,ptr->name,ptr->score);
} 
int main(int argc, char *argv[]) {
	struct student *head,*p;
	int choice,num,score;
	char name[20];
	int size=sizeof(struct student);
	do{
		puts("1:Create 2:Insert 3:Delete 4:print 0: Exit");
		scanf("%d",&choice);//cout<<"ok"<<endl;
		switch(choice){
			case 1:
				head=Create_s();
				break;
			case 2:
				puts("Input num,name and score:");
				scanf("%d%s%d",&num,name,&score);
				p=(struct student*)malloc(size);//���뵽�ڴ� 
				p->num =num;//һһ��ֵ 
				strcpy(p->name ,name);
				p->score =score;
				head=Insert_s(head,p);
				break;
			case 3:
				puts("Input num:");
				scanf("%d",&num);
				head=Dele_s(head,num);
				break;
			case 4:
				print_s(head);
				break;
			case 0:		
				break;
		}
	}while(choice!=0);
	return 0;
}
