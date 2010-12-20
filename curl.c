/*
 *
 * arv[1] is the file name in which it should be saved arv[2] = the exact url
 *
 *compilation : cc curl.c -I/usr/local/include -L/usr/local/lib -lcurl
 *
 */

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE * f1 = fopen(argv[1],"w");
	CURL * easyhandle = curl_easy_init();
	if(argc == 1){
		perror("pass the required arguments, filename and url");
		exit(1);
	}
	curl_easy_setopt(easyhandle,CURLOPT_URL,argv[2]);
	curl_easy_setopt(easyhandle,CURLOPT_WRITEDATA,f1);
	curl_easy_perform(easyhandle);
	curl_easy_cleanup(easyhandle);
	return 0;
}
