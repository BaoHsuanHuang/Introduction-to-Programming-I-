//  qqsort
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50000
typedef struct{
    int x;
    int a[9];
} Type;

int cmp(void * a, void * b){
    Type *pa = (Type *) a;
    Type *pb = (Type *) b;
    if (pa->x > pb->x) return 1;
    else if (pa->x < pb->x) return -1;
    else return 0;
        
}
void qqsort(void * a, size_t num, size_t wd,
            int (*f) (void *, void *));

int main(void) {
    Type * b;
    int i;
    time_t start, end;
    
    b = (Type *) malloc(sizeof(Type) * SIZE);
    
    for (i=0; i<SIZE; i++){
        b[i].x =  rand();
    }
    //printf("Before sorting\n");
    //for (i=0; i<SIZE; i++) printf("%lf\n", b[i]);
    start = clock();
    qqsort(b, SIZE, sizeof(Type), cmp);
    end = clock();
    printf("%f\n", (double)(end - start)/CLOCKS_PER_SEC);
    return 0;
}
void qqsort(void * a, size_t num, size_t wd,
            int (*f) (void *, void *))
{
    char * b = (char *) a;
    char * tmp;
    int mini;
    tmp = (char *)malloc(wd);
    
    int i, j;
    
    for (i=0; i<num; i++) {
        mini = i;
        for (j=i+1; j<num; j++) {
            if ( f(b + mini*wd, b + j*wd) > 0){
                // ���Ѩⵧ��ƪ��}�Y��m �p��첾�q(wd)
                // if ���� �h i����Ƥ�j����Ƥj
                // ���n�����b�o�̼g�洫�� �]�������Dtype����
                // void * memcpy(void *restrict to, const void *restrict from, size_t size);
                // �ت��a��} �ӷ���} �j�p
                mini = j;
            }
        }
        if (mini != i){
            memcpy(tmp, b+i*wd, wd);
            memcpy(b+i*wd, b+mini*wd, wd);
            memcpy(b+mini*wd, tmp, wd);
        }
    }
    free(tmp);
    
}
