#include"son.h"
void print_s(struct student *head){
	struct student *ptr;
	if(head==NULL){
		puts("\nNo Records");
		return ;
	}
	puts("\nThe Students¡¯Records Are:");
	puts("Num\t Name\t Score");
	for(ptr=head;ptr!=NULL;ptr=ptr->next)
		printf("%d\t%s\t%d\n",ptr->num ,ptr->name,ptr->score);
} 
