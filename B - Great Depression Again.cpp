#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[21];
	int A;
	int B;
	int diff;
}Factory;

Factory fac[505];

int cmp_diff(const void * a,const void * b);
int cmp_A(const void * a,const void * b);
int cmp_B(const void * a,const void * b);
int cmp_name(const void * a,const void * b);

int main(void)
{
	int n,x,y;
	int i;
	int a,b;
	int total;
	int max=0;
	int mid;
	Factory * remove;
	scanf("%d%d%d",&n,&x,&y);
	
	for(i=0;i<n;i++){
		scanf("%s%d%d",fac[i].name,&(fac[i].A),&(fac[i].B));
		fac[i].diff = fac[i].A - fac[i].B;
	}
	for(i=x;i<=n-y;i++){
		total = 0;
		qsort(fac,n,sizeof(Factory),cmp_diff);
		qsort(fac,i,sizeof(Factory),cmp_A);
		
		remove = fac+i;
		qsort(remove,n-i,sizeof(Factory),cmp_B);
		
		for(a=0;a<x;a++){
			total += fac[a].A;
		}
		for(b=i;b<i+y;b++){
			total += fac[b].B;
		}
		
		if(total > max){
			max = total;
			mid = i;
		}
	}
	
	qsort(fac,n,sizeof(Factory),cmp_diff);
	qsort(fac,mid,sizeof(Factory),cmp_A);
	qsort(fac,x,sizeof(Factory),cmp_name);
	
	for(i=0;i<x;i++){
		printf("%s\n",fac[i].name);
	}
	
	return 0;
}

int cmp_diff(const void * a,const void * b)
{
	Factory * va = (Factory *)a;
	Factory * vb = (Factory *)b;
	
	if(va->diff > vb->diff) return -1;
	else if(va->diff < vb->diff) return 1;
	else return 0;
}

int cmp_A(const void * a,const void * b)
{
	Factory * va = (Factory *)a;
	Factory * vb = (Factory *)b;
	
	if(va->A > vb->A) return -1;
	else if(va->A < vb->A) return 1;
	else return 0;
}

int cmp_B(const void * a,const void * b)
{
	Factory * va = (Factory *)a;
	Factory * vb = (Factory *)b;
	
	if(va->B > vb->B) return -1;
	else if(va->B < vb->B) return 1;
	else return 0;
}

int cmp_name(const void * a,const void * b)
{
	Factory * va = (Factory *)a;
	Factory * vb = (Factory *)b;
	
	return strcmp(va->name,vb->name);
}
