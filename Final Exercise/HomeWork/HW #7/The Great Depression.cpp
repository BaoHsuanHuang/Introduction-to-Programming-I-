#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[21];
	int A;
	int B;
	int diff;
}Factory;

Factory fac[100000];

int cmp_diff(const void *a,const void *b);
int cmp_name(const void *a,const void *b);

int main(void)
{
	int n,x,y;
	int i;
	
	scanf("%d%d%d",&n,&x,&y);
	
	for(i=0;i<n;i++){
		scanf("%s%d%d",fac[i].name,&(fac[i].A),&(fac[i].B));
		fac[i].diff = fac[i].A - fac[i].B;
	}
	
	qsort(fac,n,sizeof(Factory),cmp_diff);
	
	qsort(fac,x,sizeof(Factory),cmp_name);
	
	for(i=0;i<x;i++){
		printf("%s\n",fac[i].name);
	}
	
	return 0;
}

int cmp_diff(const void *a,const void *b)
{
	Factory * va = (Factory *)a;
	Factory * vb = (Factory *)b;
	
	if(va->diff > vb->diff) return -1;
	else if(va->diff < vb->diff) return 1;
	else return 0; 
}

int cmp_name(const void *a,const void *b)
{
	Factory * va = (Factory *)a;
	Factory * vb = (Factory *)b;
	
	return strcmp(va->name,vb->name);
}
