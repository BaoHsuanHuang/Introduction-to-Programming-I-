#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 100

int cmp(void * a,void * b)
{
	double * pa = (double *)a;
	double * pb = (double *)b;
	
	if(*pa > *pb) return 1;
	else if(*pa < *pb) return -1;
	else return 0;
}

void qqsort(void * a,size_t num, size_t wd,int (*f) (void * ,void *));

int main(void)
{
	double * b;
	int i;
	
	time_t start,end;
	
	b = (double *)malloc(SIZE * sizeof(double));
	
	for(i=0;i<SIZE;i++){
		b[i] = (double) rand()/RAND_MAX;
	}
	
	//for(i=0;i<SIZE;i++) printf("%lf\n",b[i]);
	start = clock();
	
	qqsort(b,SIZE,sizeof(double),cmp);
	
	end = clock();
	//for(i=0;i<SIZE;i++) printf("%lf\n",b[i]);
	printf("%lf\n",(double)(end-start)/CLOCKS_PER_SEC);
	
	return 0;
}
/*
void qqsort(void * a,size_t num, size_t wd,int (*f) (void * ,void *))
{
	char * b = (char *) a;
	char tmp;
	
	int i,j;
	int k;
	
	for(i=0;i<num;i++){
		for(j=i+1;j<num;j++){
			if( f(b + i*wd,b + j*wd)>0 ){
				for(k=0;k<wd;k++){		// 逐一交換每個byte 
					tmp = *(b + i*wd + k);
					*(b + i*wd + k) = *(b + j*wd + k);
					*(b + j*wd + k) = tmp;
				}

			}
		}
	}
}
*/

/*
void qqsort(void * a,size_t num, size_t wd,int (*f) (void * ,void *))
{
	char * b = (char *) a;
	char * tmp;
	
	tmp = (char *)malloc(wd);
	
	int i,j;
	int k;
	
	for(i=0;i<num;i++){
		for(j=i+1;j<num;j++){
			if( f(b + i*wd,b + j*wd)>0 ){
				memcpy(tmp,b +i*wd,wd);
				memcpy(b+i*wd,b+j*wd,wd);
				memcpy(b+j*wd,tmp,wd);
			}
		}
	}
	free(tmp);
}
*/

void qqsort(void * a,size_t num, size_t wd,int (*f) (void * ,void *))
{
	char * b = (char *) a;
	char tmp;
	int mini;
	tmp = (char *)malloc(wd);
	int i,j;
	int k;
	
	for(i=0;i<num;i++){
		mini = i;
		for(j=i+1;j<num;j++){
			if( f(b + mini*wd,b + j*wd)>0 ){
				mini = j;
			}
		}
		if(mini != i){
			memcpy(tmp,b+i*wd,wd);
			memcpy(b+i*wd,b+mini*wd,wd);
			memcpy(b+mini*wd,tmp,wd);
		}

	}
}
