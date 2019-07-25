#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
struct student{
	int num;
	char name[20];
	int score;
	struct student *next;
};
struct student *Insert_s(struct student *head, struct student *stud);
struct student*Create_s();
void print_s(struct student *head);
struct student *Dele_s (struct student *head,int num);
using namespace std;
