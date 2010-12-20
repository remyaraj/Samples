/*
 *    implementation of md5sum command in c
 *
 *    cc md5sm.c -lssl
 */

#include <stdio.h>
#include <openssl/md5.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
  	int n,fd;
   	MD5_CTX c;
   	char buf[512];
   	ssize_t bytes;		
	unsigned char out[MD5_DIGEST_LENGTH];

    MD5_Init(&c);
	fd = open(argv[1],O_RDONLY);
   	bytes=read(fd, buf, 512);
   	while(bytes > 0)
   	{
     	MD5_Update(&c, buf, bytes);
      	bytes=read(fd, buf, 512);
   	}

   	MD5_Final(out, &c);

  	for(n=0; n<MD5_DIGEST_LENGTH; n++)
      	printf("%02x", out[n]);
	
	printf("\n");

  	return(0);        
}
