#include <stdio.h>
int merge(int *a,int *b,int *c,int alen,int blen)
{
    int i=0,j=0,k=0;
    for(k=0;(i<alen) || (j<blen);k++){
        if(a[i]<b[j]){
            c[k] = a[i];
            i++;
        }
        else{
            c[k] = b[j];
            j++;
        }
    }
	return k;
}
int main()
{
	int a[]={1,3,7,8};
	int b[]={2,5,8,10,16};
	int c[100],k,i;
	k=merge(a,b,c,4,5);
	for(i=0;i<k;i++)
		printf("%d\t",c[i]);
	printf("\n");
	return 0;
}
