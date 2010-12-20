/*
 *  Linked list : append , reversal, recursive reversal
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;
}*start=NULL,*last=NULL;

void show()
{
	struct node *p;
	p=start;
	while(p!=NULL){
		printf("%d->",p->value);
		p = p->next;
	}
	printf("\n");
}

void append(struct node *new)
{
	struct node *temp;
	temp=start;
	if(start==NULL){
		start = new;
		last = new;
		return;
	}
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = new;
	last = new;
	return;
}

struct node * newnode(int num)
{
	struct node * temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->value = num;
	temp->next = NULL;
	return temp;
}

struct node * reverse1(struct node *root)
{
	struct node *t1;
	if(root==NULL){
		perror("Empty list...");
		return;
	}else if(root==last){
		return root;	
	}else{
		t1 = reverse1(root->next);
		root->next->next = root;
		root->next = NULL; 
		return t1;
	}
}

void reverse()
{
	struct node *t1;
	struct node *t2;
	struct node *temp;
	t1=start;
	if(start == NULL){
		perror("Empty list");
		return;
	}
	else if(start == last){
		return;
	}
	else{
		t2= start->next;
		while(t2!=NULL){
			temp = t2->next;
			t2->next = start;
			start = t2; 
			t2 = temp;
		}
		t1->next=NULL;
		last = t1;
	}
	return;	
}

void maintain()
{
	struct node *temp;
	temp = start;
	if((start == NULL)|| (start->next ==NULL))
		last = start;
	else{
		while(temp->next!=NULL)
			temp = temp->next;
		last = temp;
	}
	return;
}

void make_choice(int choice)
{
	int num;
	switch(choice){
		case 1:
			printf("Enter the number\n");
			scanf("%d",&num);
			append(newnode(num));
			show();
			break;
		case 2:
			reverse();
			show();
			break;
		case 3:
			start = reverse1(start);
			maintain();
			show();
			break;
		default:
			exit(0);
	}
	return;
}

int main()
{
	int i;
	while(1){
		printf("Enter the choice\n1.append\n2.reverse\n3.reverse1\n4.exit\n");
		scanf("%d",&i);
		make_choice(i);
	}
	return 0;
}
