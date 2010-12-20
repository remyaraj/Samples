/*
 *  Doubly linked Circular list - insertion and printing
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *previous;
	struct node *next;
};


void print(struct node *p1)
{
	struct node *temp;
	temp = p1;
	if(p1==NULL){
		perror("No elements in the array\n");
		return;
	}
	do{
		printf("%d->",temp->data);
		temp = temp->next;
	}while(temp!=p1);
	printf("\n");
	return;
}

struct node *newnode(int a)
{
	struct node *temp = NULL;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = a;
	temp->previous = NULL;
	temp->next = NULL;
	return temp;
}

struct node *insert(struct node *last,struct node *new)
{
	if(last == NULL){
		new->previous = new;
		new->next = new;
		return new;
	}
	else{
		new->next = last->next;
		new->previous = last;
		last->next->previous = new->next;
		last->next = new;
	}
	return new;
}


int main()
{	
	struct node *last=NULL;
	int i,a;	
	while(1){
		printf("Enter the choice 1. insertion 2.Exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("Enter the data\n");
				scanf("%d",&a);
				last = insert(last,newnode(a));
				print(last);
				break;
			default:
				exit(1);
		}
	}
	return 0;
}
