#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

int* readInput();
void my_sort(int* B);
int cmp(const void *a,const void *b);

int* readInput() {
    int i, N, *seq;
    scanf("%d", &N);
    seq = (int*)malloc(sizeof(int)*(N + 1));
    seq[0] = N;
    for(i=1; i<N+1; i++)
        scanf("%d", &seq[i]);
    return seq;
}

int main() {
    int i;
    int *A = readInput(); //指標A : 紀錄一塊空間的開頭位置 
    my_sort((int*)&A);
    printf("%d", A[1]);
    for(i=2;i<A[0]+1;i++)
        printf(" %d", A[i]);
    printf("\n");
    return 0;
}

int cmp(const void *a,const void *b)
{
	int * va = (int *)a;
	int * vb = (int *)b;
	
	if( *va > *vb) return 1;
	else if( *va < *vb) return -1;
	else return 0;
}

void my_sort(int* B) //B : 紀錄A的位置 
{
	qsort( *(int **)B +1 , **(int **)B ,sizeof(int),cmp);		//point : 要先強制轉換型別 
	//qsort( *B +1 , **B ,sizeof(int),cmp);
}
