#include"son.h"
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
