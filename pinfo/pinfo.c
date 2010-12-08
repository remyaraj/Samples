#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


struct pinfo{
	char company[200];
	char proc_name[200];
	char speed[200];
	char architecture[200];
	int nbits;
};



struct pinfo * assign_struct(char *buf)
{
	struct pinfo *p;
	char *c;
	p = (struct pinfo *)malloc(sizeof(struct pinfo));
	c = strstr(buf,":");
	if(c){
		buf[c-buf]='\0';
		strncpy(p->company,buf,c-buf+1);
	}
	buf =c+1;
	c=strstr(buf,":");
	if(c){
		buf[c-buf]='\0';
		strncpy(p->proc_name,buf,c-buf+1);
	}
	buf = c+1;
	c=strstr(buf,":");
	if(c){
		buf[c-buf]='\0';
		strncpy(p->speed,buf,c-buf+1);
	}
	buf = c+1;
	c=strstr(buf,":");
	if(c){
		buf[c-buf]='\0';
		strncpy(p->architecture,buf,c-buf+1);
	}
	buf=c+1;
	p->nbits = atoi(buf);
	return p;
}

int check(char* buf,char *pattern)
{
	char *s;
 	s=strstr(buf,":");
	if(s){
		return strncmp(&s[1],pattern,strlen(pattern));
	}
	else
		printf("error\n");
}

struct pinfo * get_processor_info(char *filename, char *pattern)
{
    FILE *fd;
	int i=0;
	char *temp;
	char buf[10000];
    struct pinfo *p;
    fd = fopen("sample.txt","r");
    if(fd<0){
        fprintf(stderr,"no file opened for reading");
        exit(1);
    }
    while((fgets(buf,10000,fd))!=NULL){
		if (strlen(buf) == 1)
			continue;
		buf[strlen(buf)-1]='\0';
		temp = buf;
		i = check(buf,pattern);
		if(i==0){
			p=assign_struct(temp);
		}
	}
	return p;
}

int main()
{
        struct pinfo *p; 

        p = get_processor_info("sample.txt", "pic");

        if(p == 0) {
                fprintf(stderr, "no such processor in database\n");
                exit(1);
        }
		printf("\n");
        printf("%s %s %s %d\n", p->company, p->speed, p->architecture, p->nbits);
		return 0;
}

