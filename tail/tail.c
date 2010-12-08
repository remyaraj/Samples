#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


void tail_1(char *filenam)
{
    FILE *fd;
    int k;
    char buf[1000];
    struct stat statbuf;
    fd = fopen(filenam,"r");
	if(fd==NULL){
		fprintf(stderr,"error in opening the file");
	}
	stat(filenam,&statbuf);
	if((int)statbuf.st_size > 52)
	    k = fseek(fd,-52,SEEK_END);
    if(k<0){
		fprintf(stderr,"error in seeking the position");
		exit(1);
	}
    while(fgets(buf,1000,fd))
        printf("%s",buf);
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
