#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "function.h"

typedef struct {
	int value;
	char str[30];
	float x;
} MyData;

int compare_function(const void* a, const void* b);


int main(void)
{


	MyData data[100];
	MyData* book[100];
    int i, size;

    //freopen("test_in4.txt", "r", stdin);
    //freopen("test_out4.txt", "w", stdout);

    scanf("%d", &size);

	for (i = 0; i < size; i++) {
        scanf("%d", &data[i].value);
	}
    for (i = 0; i < size; i++) {
        scanf("%s", data[i].str);
	}
    for (i = 0; i < size; i++) {
        scanf("%f", &data[i].x);
	}
    for (i = 0; i < size; i++) {
		book[i] = &data[i];
	}


	qsort(book, size, sizeof(MyData*), compare_function);

	for (i=size-1; i>=0; i--) {
		printf("%d %s %.3f\n", book[i]->value, book[i]->str, book[i]->x);
    }

	return 0;

}

int compare_function(const void* a, const void* b)
{
	MyData* *va = (MyData* *)a;
	MyData* *vb = (MyData* *)b;
	
	if( (*va)->value > (*vb)->value) return 1;
	else if((*va)->value < (*vb)->value) return -1;
	else{
		if( strcmp((*va)->str,(*vb)->str) );
		//if((*va)->str > (*vb)->str) return 1;
		//else if((*va)->str < (*vb)->str) return -1;
		else{
			if((*va)->x > (*vb)->x) return 1;
			else if((*va)->x < (*vb)->x) return -1;
			else return 0;
		}
	}
	
} 


