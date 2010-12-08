#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash{
	char word[20];
	struct hash *next;
};

void print(struct hash *);


struct hash * newnode(char *buf)
{
	struct hash *temp;
	temp = (struct hash *)malloc(sizeof(struct hash));
	strcpy(temp->word,buf);
	temp->next = NULL;
	return temp;
}

int check(char *buf)
{
	return buf[0]-'a';
}

struct hash *linked_list(struct hash*newnode,struct hash *start )
{
	struct hash *temp;
	temp = start;
	if(start==NULL){
		return newnode;
	}
	while(temp->next!=NULL)
		temp = temp->next;
	temp->next  = newnode;
	return start;
}

void print(struct hash *start)
{
	while(start->next!=NULL){
		printf("%s->",start->word);
		start = start->next;
	}
	printf("%s",start->word);
}



int main()
{
	FILE *f1;
	char buf[1000];
	struct hash *hsh[25];
	int alph,i;
	struct hash *nw;
	for(i=0;i<26;i++){
		hsh[i] = NULL;
	}
	f1 = fopen("lib.txt","r");
	if(f1== NULL){
		fprintf(stderr,"error in opening file");
		exit(1);
	}
	while(fgets(buf,1000,f1)!=NULL){
		if(strlen(buf)==1)
			continue;
		buf[strlen(buf)-1] = '\0';
		nw = newnode(buf);
		alph = check(buf);
		hsh[alph] = linked_list(nw,hsh[alph]);
	}
	for(i=0;i<26;i++){
		if(hsh[i]==NULL)
			continue;
		print(hsh[i]);
		printf("\n");
	}
	
	return 0;
}
