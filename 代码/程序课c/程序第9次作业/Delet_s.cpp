#include"son.h"
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
	while(ptr2!=NULL/*Ҫɾ���Ĵ���*/){
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
