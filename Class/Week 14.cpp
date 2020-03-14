
// qsort //

#include <stdio.h>
#include <stdlib.h>		// --> rand()
#include <string.h>
#define SIZE 10

// void qsort (void *array, size_t count, size_t size, comparison_fn_t compare);

// qsort 可吃 int 的指標變數( data 1 ) ， 也可以吃 char 的指標變數 ( data 2 ) --> 設 void * p 
// 變數 4 的宣告 : 例如宣告一個函數 int function(int , double)  改成指標 -->  int (* f)(int , double) 


int compare_int (const void *a, const void *b)		// const : 代表 " 唯讀 " ( 只能讀資料， 不能改裡面的資料 ) 
{
    const int *va = (const int *) a;
    const int *vb = (const int *) b;
    //return *va-*vb;
    if (* va > *vb) return 1;
    else if(*va < *vb) return -1;
    else return 0;
}
int compare_double (const void *a, const void *b)
{
    const double *da = (const double *) a;
    const double *db = (const double *) b;
    //return (*da > *db) - (*da < *db);		// 用 true (1) 和 false(0) 來運算 
    if (* da > *db) return 1;
    else if(*da < *db) return -1;
    else return 0;
}

int main(void)
{
    int data1[SIZE];
    double data2[SIZE];
    int i;

    for (i=0; i<SIZE; i++) {
        data1[i] = rand()%SIZE;		// rand() : 隨機回傳一個整數( 0 ~ RAND_MAX ) 
        data2[i] = (double) rand()/RAND_MAX;	// 強制轉成 double 
    }

    printf("original: ");
    for (i=0; i<SIZE; i++) {
        printf("%d ", data1[i]);
    }
    printf("\n");

    printf("  sorted: ");
    qsort(data1, SIZE, sizeof(int), compare_int);// 變數 1 : date1 -> 資料在哪裡 ( array 開頭位置 )  
    for (i=0; i<SIZE; i++) {					// 變數 2 : 有幾個元素 
        printf("%d ", data1[i]);				// 變數 3 : 每個元素占多少空間 
    }									// 變數 4 : 比大小的函數 ， 傳函數的名稱進去-->去找函數在記憶體的位置執行函數裡面的指令 
    printf("\n");

    printf("original: ");
    for (i=0; i<SIZE; i++) {
        printf("%.2f ", data2[i]);
    }
    printf("\n");

    printf("  sorted: ");
    qsort(data2, SIZE, sizeof(double), compare_double);
    for (i=0; i<SIZE; i++) {
        printf("%.2f ", data2[i]);
    }
    printf("\n");

    return 0;
}







// 對固定長度的字元陣列排序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int main(void)
{
	// 'a','a','b','\0','a','b','c','\0'......
    char strs[SIZE][4] ={
        "aab", "abc", "aaa", "abb", "acb",
        "aab", "abc", "aaa", "abb", "acb"
    };
    int i;

    for (i=0; i<SIZE; i++) {
        printf("%s\n", strs[i]);
    }
    printf("\n");
    qsort(strs, SIZE, 4*sizeof(char), (int (*) (const void *, const void *))strcmp);
    for (i=0; i<SIZE; i++) {			// (int (*) (const void *, const void *)) 強制轉型 
        printf("%s\n", strs[i]);
    }

    return 0;
}
// 函數strcmp : 比較字串大小順序 
// int strcmp(const char * s , const char * t);
// while(*s != '\0' && *t != '\0').......












#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int compare_str_ptr(const void *a, const void *b)
{
    char **pa;		// 門牌號碼的type : char *		// 記門牌號碼的記憶體位置 : char ** 
    char **pb;
    pa = (char **) a;
    pb = (char **) b;
    return strcmp(*pa, *pb);
}

int main(void)
{
    char strs[SIZE][4] ={
        "aab", "abc", "aaa", "abb", "acb",
        "aab", "abc", "aaa", "abb", "acb"
    };
    char *ptrs[SIZE];
    int i;

    for (i=0; i<SIZE; i++) {
        printf("%s\n", strs[i]);
    }
    printf("\n");


    for (i=0; i<SIZE; i++) {
        ptrs[i] = strs[i];
    }
    qsort(ptrs, SIZE, sizeof(char*), compare_str_ptr);
    for (i=0; i<SIZE; i++) {
        printf("%s\n", ptrs[i]);
    }
    printf("\n");
    for (i=0; i<SIZE; i++) {
        printf("%s\n", strs[i]);
    }


    return 0;
}












// 動態
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int main(void)
{
	int * a;
	int num,i;
	scanf("%d",num);
	
	a = (int *) malloc(num * sizeof(int));		// malloc 傳回記憶體的開頭位置 
		// 強制轉型 // 
		
	if(a == NULL) return -1;		// NULL == 0	 
	for(i=0;i<num;i++){
		a[i] = rand()%num;		// * (a+i) = a[i]
	}
	
	double * z;
	z = (double * ) malloc(num*sizeof(double));

	i = rand()%num;
	printf("%d %D\m",i,a[i]);
	
	free(a);
	
	a = NULL;
	if(a != NULL){
		.....
	}

	return 0;
}







#include <string.h>
#define SIZE 10

int * f(int i)
{
	int s[5] = {4,5,6,7,8};
	return &s[i];
}

int main(void)
{
	int * a;
	a = f(3);
	
	return 0;
}






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int main(void)
{
	int a[5][7];
	int i,j;
	
	int *  * pa;
	
	int * x;
	a = (int *) malloc(5*7*sizeof(int));
	
	pa = (int * *)malloc(5*sizeof(int *));
	for(i=0;i<5;++){
		pa[i] = &x[i*7];
	}
	for(i=0;i<5;i++){
		for(j=0;j<7;j++){
			pa[i][j] = rand()%35;
		}
	}
	// 5 就是 row
	// 7 就是 col 
	for(i=0;i<5;i++){
		for(j=0;j<7;j++){
			printf("%3d",pa[i][j]);
		}
		printf("\n");
	}
	
	free(x);
	free(pa);
	/*
	for(i=0;i<5;i++){
		pa[i] = (int *)malloc(7*sizeof(int));
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<7;j++){
			pa[i][j] = rand()%35;
		}
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<7;j++){
			printf("%3d",pa[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<5;i++){
		free(pa[i]);
	}
	
	free(pa);
	*/
	
//	return 0;
//}





 




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int x;
	int y;
	double speed;
	
} Car;

int cmp(const void * a,const void * b);

void showcar(Car * pc)
{
	printf("%d %d %lf\n", pc->x , pc->y , pc->speed);
}

int main(void)
{
	int i;
	
	Car * cars;
	Car *ptrs[100];
	
	cars = (Car *)malloc(100*sizeof(Car));
	
	for(i=0;i<100;i++){
		cars[i].x = rand()%1000;
		cars[i].y = rand()%1000;
		cars[i].speed = 300*(double)rand()/RAND_MAX;
	} 
	
	for(i=0;i<100;i++){
		ptrs[i] = &cars[i];
	}
	
	for(i=0;i<100;i++){
		//showcar(&cars[i]);
		showcar(ptrs[i]);
	}
	
	//qsort(cars,100,sizeof(Car),cmp);
	qsort(ptrs,100,sizeof(Car *),cmp);
	
	printf("===========================\n");
	
	for(i=0;i<100;i++){
		//showcar(&cars[i]);
		showcar(ptrs[i]);
	}
	return 0;
}



int cmp(const void * a,const void * b)
{
	//Car * pa = (Car *) a;
	//Car * pb = (Car *) b;
	
	Car * * pa = (Car **) a;
	Car * * pb = (Car **) b;
	if ( (*pa)->speed > (*pb)->speed) return 1;
	else if ( (*pa)->speed < (*pb)->speed) return -1;
	else return 0;
	
		//if ( (*pa).speed > (*pb),speed) return 1;
		//else if ( (*pa).speed < (*pb),speed) return -1;
		//else return 0;
	//if ( pa->speed > pb->speed) return 1;
	//else if ( pa->speed < pb->speed) return -1;
	//else return 0;
} 















