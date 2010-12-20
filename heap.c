/*
 * heap creation from a static array and implementation of heap sort
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MINDATA -32767

struct heap{
	int capacity;
	int size;
	int *elements;
};

struct heap *initialize(int *a)
{
	struct heap *temp;
	temp = (struct heap *)malloc(sizeof(struct heap));
	temp->elements = a;
	temp->capacity = MAX_SIZE;
	temp->size = 0;
	temp->elements[0] = MINDATA;
	return temp;
}

void insert(int x,struct heap *h)
{
	int i;
	if(h->size == h->capacity){
		perror("Array reached maximum size");
		exit(1);
	}
	for(i=++h->size;h->elements[i/2]>x;i=i/2){
		h->elements[i] =h->elements[i/2];
	}
	h->elements[i] = x;
}

void print(struct heap *h)
{
	int i;
	for(i=1;i<=h->size;i++){
		printf("%d->",h->elements[i]);
	}
	printf("\n");
}

int main()
{	
	int a[MAX_SIZE];
	int i,val;
	struct heap *h=NULL;
	h = initialize(a);
	while(1){
		printf("Enter the choice 1.insertion 2. print 3. Exit\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				printf("Enter the number\n");
				scanf("%d",&val);
				insert(val,h);
				break;
			case 2:
				print(h);
				break;
		}
	}
	return 0;
}
