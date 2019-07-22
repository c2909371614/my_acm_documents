#include"son.h"
struct student *Insert_s(struct student *head, struct student *stud){
	struct student *ptr,*ptr1=NULL,*ptr2; 
	ptr2=head;//指向当前地址 
	ptr=stud;//ptr指向待插入 的新生记录结点
	/*原链表为空时*///cout<<"ok\n"<<head<<endl; 
	if(head==NULL){
		head=ptr;
		head->next =NULL;
	}
	else {
		while((ptr->num>ptr2/*head*/->num)&&(ptr2->next!=NULL)){
			ptr1=ptr2;//ptr1为辅助指针 
			ptr2=ptr2->next;//ptr1 ptr2 后移 
		}
		if(ptr->num <=ptr2->num ){//在1 和2之间插入
			if(head==ptr2)// because ptr2->next==NULL;
				head=ptr;
			else 
				ptr1->next =ptr;

			ptr->next=ptr2; //向后链接 
		} 
		else {//ptr2->next==NULL;
			ptr2->next=ptr;
			ptr->next=NULL;
		}
	} 
	return head;	
}
