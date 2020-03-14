#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "function.h"

typedef struct {
	int zipcode;
	char name[15];
} Letter;

int compare(const void *,const void *);

int main(void)
{
	int n;

	// Read inputs
	scanf("%d",&n);
	Letter *letters=(Letter*)malloc(sizeof(Letter)*n);

	int i;
	for(i=0; i!=n; ++i)
		scanf("%d %s",&(letters[i].zipcode),letters[i].name);

	// Sort the data
	qsort(letters,n,sizeof(Letter),compare);

	// Output result
	for(i=0; i!=n; ++i)
		printf("%d %s\n",letters[i].zipcode,letters[i].name);

	free(letters);
}

int compare(const void * a,const void * b)
{
	Letter * va = (Letter *)a;
	Letter * vb = (Letter *)b;
	
	if(va->zipcode > vb->zipcode) return 1;
	else if(va->zipcode < vb->zipcode) return -1;
	else{
		return strcmp(va->name , vb->name);
	}
}
