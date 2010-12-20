/*
 *
 * Binary Search Tree : Insertion & in_order printing
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct binarynode{
	int value;
	struct binarynode *left;
	struct binarynode *right;
}*root=NULL;

struct binarynode * insert(struct binarynode * new,struct binarynode *t1)
{
	if(t1 == NULL){
		return new;
	}
	if(t1->value > new->value){
		t1->left = insert(new,t1->left);
	}
	else{
		t1->right = insert(new,t1->right);
	}
	return t1;
}

struct binarynode * newnode(int num)
{
	struct binarynode *p;
	p = (struct binarynode *)malloc(sizeof(struct binarynode));
	p->value = num;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void in_order(struct binarynode *t1)
{
	if(t1==NULL){
		return;
	}
	else{
		in_order(t1->left);
		printf("%d->",t1->value);
		in_order(t1->right);
	}
}

void make_choice(int choice)
{
	int val;
	switch(choice){
		case 1:
			printf("Enter the number\n");
			scanf("%d",&val);
			root = insert(newnode(val),root);
			break;
		case 2:
			in_order(root);
			break;
		default:
			exit(1);
	}
}

int main()
{
	int ch;
	while(1){
		printf("Enter the choice:\n1. Insertion \n2.Inorder \n3.EXIT\n");
		scanf("%d",&ch);
		make_choice(ch);
	}
	return 0;
}
