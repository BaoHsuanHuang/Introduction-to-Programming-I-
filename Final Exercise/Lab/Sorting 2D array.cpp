#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

int compare (const void *pa, const void *pb);

int main(void){
    int **array;
    int i, number;

    scanf("%d", &number);

    /** Dynamically create 2d array **/
    array = (int **)malloc(number * sizeof(int*));
    for (i = 0; i < number; i++){
        array[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d %d", &array[i][0], &array[i][1]);
    }

    qsort(array, number, sizeof array[0], compare);

    for(i = 0; i < number; ++i)
        printf("%3d %3d\n", array[i][0], array[i][1]);

    return 0;
}

int compare (const void *pa, const void *pb)
{
	int ** va = (int **)pa;
	int ** vb = (int **)pb;
	
	if((*va)[0] > (*vb)[0]) return 1;
	else if((*va)[0] < (*vb)[0]) return -1;
	else{
		if((*va)[1] > (*vb)[1]) return 1;
		else if((*va)[1] < (*vb)[1]) return -1;
		else return 0;	
	}
}
