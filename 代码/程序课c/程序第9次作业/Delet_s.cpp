#include"son.h"
struct student *Dele_s(struct student *head,int num){
	struct student *ptr1,*ptr2;
	while(head!=NULL&&head->num ==num){
		ptr2=head;
		head=head->next ;
		free(ptr2);//先free内存
	}
	if(head==NULL)
		return NULL;//链表为空
	ptr1=head;
	ptr2=head->next;
	//从表头的下一个结点搜索所有符合删除要求的结点
	while(ptr2!=NULL/*要删除的存在*/){
		if(ptr2->num ==num){
			ptr1->next=ptr2->next ;
			free(ptr2); 
		}		
		else 
			ptr1=ptr2;//后移 
		ptr2=ptr1->next; //ptr指向ptr1的下一个个结点 
	} 
	return head; 
}
