#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>



void tail_1(char *filename)
{
	char * lines[100];
	char buf[1000];
	int i=0,j;
	FILE * fd;
	fd = fopen(filename,"r");
	if(fd == NULL){
		fprintf(stderr,"error in opening file");
	}
	while((fgets(buf,1000,fd))!=NULL){
		buf[strlen(buf)-1]='\0';
		lines[i]=(char *)malloc(sizeof(buf));
		strcpy(lines[i],buf);
		i++;
	}
	if(i>10)
		j = i-10;
	else
		j=0;
	while(j<i){
		printf("%s\n",lines[j]);
		j++;
	}
}


int main(int argc, char * argv[])
{
	char buf[1000];
	int i;
	if(argc==1){
		while(fgets(buf,1000,stdin)!=NULL);
	}
	else if(argc==2){
		tail_1(argv[1]);
	}
	else{
		for(i=1;i<argc;i++){
			printf("==> %s <==\n",argv[i]);
			tail_1(argv[i]);
		}
	}
	return 0;
}
