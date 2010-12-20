/*
 *  representing polynomials using linked list & adding it iteratively
 */

#include <stdio.h>
#include <stdlib.h>

struct polynomial{
	int data;
	int exponent;
	struct polynomial *next;
};

struct polynomial * newnode(int dat, int exp)
{
	struct polynomial * temp;
	temp = (struct polynomial *)malloc(sizeof(struct polynomial));
	temp->data = dat;
	temp->exponent = exp;
	temp->next = NULL;
	return temp;
}

struct polynomial *append(struct polynomial * t1,struct polynomial *t2)
{
	struct polynomial *temp;
	temp = t1;
	if(t1==NULL)
		return t2;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next = t2;
	return t1;
}

void print(struct polynomial *t1)
{
	while(t1!=NULL){
		printf("(%d %d)+",t1->data,t1->exponent);
		t1 = t1->next;
	}
	printf("\n");
}

struct polynomial *create_poly()
{
	struct polynomial * t1=NULL;
	int i=0,j=0,v1=0,v2=0;   	
	printf("Enter the number of terms\n");
	scanf("%d",&i);
	for(j=0;j<i;j++){
		scanf("%d %d",&v1,&v2);
		t1 = append(t1,newnode(v1,v2));
	}
	return t1;
}

struct polynomial * add1(struct polynomial *p1,struct polynomial *p2)
{
	struct polynomial * temp= NULL;
	if(p1==NULL)
		return p2;
	else if(p2==NULL)
		return p1;
	else{
		if(p1->exponent > p2->exponent)
			p1->next = add1(p1->next,p2);
		else if(p1->exponent < p2->exponent){
			p1 = add1(p2,p1);
		}else{
			p1->data = p1->data + p2->data;
			p1->next = add1(p1->next,p2->next);
		}   
		return p1;
	}
}

struct polynomial * add(struct polynomial *p1,struct polynomial *p2)
{
	struct polynomial *sum = NULL;
	while((p1!=NULL) && (p2!=NULL)){
		if(p1->exponent > p2->exponent){
			sum = append(sum,newnode(p1->data,p1->exponent));
			p1 = p1->next;
		}else if(p1->exponent < p2->exponent){
			sum = append(sum,newnode(p2->data,p2->exponent));
			p2 = p2->next;
		}else{
			sum = append(sum,newnode((p1->data + p2->data),p1->exponent));
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	if(p1==NULL){
		sum = append(sum,p2);
	}else if(p2==NULL){
		sum = append(sum,p1);
	}
	return sum;
}


int main()
{
	int i=0,j,v1,v2;
	struct polynomial *p1=NULL;
	struct polynomial *p2=NULL;
	struct polynomial *sum = NULL;
	p1 = create_poly();
	print(p1);
	p2 = create_poly();
	print(p2);
	sum = add(p1,p2);
	printf("The sum is \n");
	print(sum);
	return 0;
}


