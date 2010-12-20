/*
 *
 *Binary search tree with file reading & each word in file form the nodes of tree with a count field which gives the occurance of the word in file
 * 
 *Print all the nodes in a level
 *
 *delete the tree by passing
 *
 *count all the nodes in binary search tree
 *
 *find the depth of the binary tree
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 10000

struct node{
	char *word;
	int count;
	struct node *left;
	struct node *right;
};

int compare(struct node *r1,char *w1)
{
	int c;
	if(r1==NULL)
		return 0;
	if(!strcasecmp(r1->word,w1)){
		r1->count = r1->count +1;
		return 1;
	}
	else if(strcasecmp(r1->word,w1)>0){
		c = compare(r1->left,w1);
	}
	else
		c  = compare(r1->right,w1);
	
	return c;
	
}

struct node *newnode(char *w2)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->word = w2;
	temp->count = 1;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


struct node * insert(struct node * t1,struct node *new)
{
    if(t1 == NULL){
        return new;
    }
    if(strcasecmp(t1->word,new->word)>0){
        t1->left = insert(t1->left,new);
    }
    else{
        t1->right = insert(t1->right,new);
    }
    return t1;
}



void print_in_order(struct node *t1)
{
    if(t1==NULL){
        return;
    }
    else{
        print_in_order(t1->left);
        printf("%s %d\n",t1->word,t1->count);
        print_in_order(t1->right);
    }
}

void delete(struct node *t1)
{
	
	if(t1==NULL){
		return;
	}
	else{
		delete(t1->left);
		delete(t1->right);
		free(t1->word);
		free(t1);
	}
	return;
}

int count_nodes(struct node *t1,int count)
{
	int c=0;
	if(t1==NULL)
		return count-1;
	else{
	c = count_nodes(t1->left,count+1);
	
	c = count_nodes(t1->right,c+1);
	return c;
	}
}

void print_nodes_in_level(struct node *t1,int i,int level)
{
	i = i+1;
	if(t1==NULL){
		return;
	}
	else{
		print_nodes_in_level(t1->left,i,level);
	if(i==level)
		printf("(%s %d)",t1->word,t1->count);
		print_nodes_in_level(t1->right,i,level);
	}
	return;
}

int height(struct node *t1)
{
	if(t1 == NULL)
		return 0;
	else{
		 if((height(t1->right))>=(height(t1->left)))
			return (height(t1->right))+1;
		else
			return (height(t1->left))+1;
	}
}

int main()
{
	int fd,n,i,j,count,ht;
	struct node *root=NULL;
	char buf[BUFSIZE];
	char temp[100];
	char *t1=NULL;
	fd = open("a.txt",O_RDONLY);
	n=read(fd,buf,BUFSIZE);
	#ifdef Debug
	for(i=0;(i<n);i++){
		printf("%c",buf[i]);
	}
	#endif

	for(i=0;i<n;){
		for(j=0;j<n;){
			if((buf[i]=='\t')||(buf[i]=='\n')||(buf[i]==' ')){
				i++;
				break;
			}
			temp[j++]=buf[i++];
		}
		temp[j]='\0';
		t1 = (char *)malloc(sizeof(temp));
		strcpy(t1,temp);
		if(!compare(root,t1)){
			root = insert(root,newnode(t1));
		}
	}
	print_in_order(root);
	printf("\n");
	print_nodes_in_level(root,0,5);
	printf("\n");
	count = count_nodes(root,1);
	printf("Total nodes = %d\n",count);
	ht = height(root);
	printf("Depth of tree = %d\n",ht);
	delete(root);
	return 0;
}
