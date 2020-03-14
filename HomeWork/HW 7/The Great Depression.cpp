#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[21];
	long long int A;
	long long int B;
	long long int diff;
}Factory;

int cmp(const void * a, const void * b);
int cmp2(const void * a, const void * b);

int main(void)
{
	int n,x,y;
	int i;
	
	scanf("%d%d%d",&n,&x,&y);
	
	Factory* fac = (Factory*)malloc(n * sizeof(Factory));
	
	for(i=0;i<n;i++){
		scanf("%s%lld%lld",fac[i].name,&(fac[i].A),&(fac[i].B));
		fac[i].diff = fac[i].A - fac[i].B;
	}
	
	qsort(fac,n,sizeof(Factory),cmp);
	
	/*
	if(fac[x].A != fac[x+1].A ){
		qsort(fac,x,sizeof(Factory),cmp2);
	}
	else{
		for(i=x+1;i<n;i++){
			if( fac[x].A == fac[i].A ){
				qsort(fac,i,sizeof(Factory),cmp2);
			}
		}
	}
	*/
	qsort(fac,x,sizeof(Factory),cmp2);
	
	for(i=0;i<x;i++){
		printf("%s\n",fac[i].name);
	}
	return 0;
}

int cmp(const void * a, const void * b)
{
	Factory *va = (Factory *)a;
	Factory *vb = (Factory *)b;
	
	if(va->diff < vb->diff) return 1;
	else if(va->diff > vb->diff) return -1;
	else return 0;
}

int cmp2(const void * a, const void * b)
{
	Factory * va = (Factory *)a;
	Factory * vb = (Factory *)b;
	
	return strcmp(va->name,vb->name);
	/*
	if((va->name)[0] > (vb->name)[0]) return 1;
	else if((va->name)[0] < (vb->name)[0]) return -1;
	else return 0;
	*/
	/*
	else{
		if((va->name)[1] > (vb->name)[1]) return 1;
		else if((va->name)[1] < (vb->name)[1]) return -1;
		else return 0;
	}
	*/
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char brand[20];
    long long int A;
    long long int B;
    long long int diff;
} CAR;
int cmp_int(const void *a, const void *b) {
    const CAR * pa = (const CAR *) a;
    const CAR * pb = (const CAR *) b;
    
    return (int)(pb->diff - pa->diff);
}
int cmp_str(const void *a, const void *b) {
    const char ** pa = (const char **) a;
    const char ** pb = (const char **) b;
    return strcmp(*pa, *pb);
}
int main(void) {
    int n, x, y, i;
    scanf("%d%d%d", &n, &x, &y);
    
    CAR car[n];
    
    CAR * car_pt;
    car_pt = car;
    char * car_brand_ptrs[x];
    
    for (i=0; i<n; i++) {
        scanf("%s %lld%lld", car[i].brand, &car[i].A, &car[i].B);
        car[i].diff = car[i].A - car[i].B;
    }
    qsort(car_pt, n, sizeof(CAR), cmp_int);
    
    for (i=0; i<x; i++) {
        car_brand_ptrs[i] = car[i].brand;
    }
    qsort(car_brand_ptrs, x, sizeof(char*), cmp_str);
    
    for (i=0; i<x; i++) {
        printf("%s\n", car_brand_ptrs[i]);
    }
    return 0;
}
*/
