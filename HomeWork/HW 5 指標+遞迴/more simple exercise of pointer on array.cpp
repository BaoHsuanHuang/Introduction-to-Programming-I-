#include <stdio.h>
#include "function.h"
void array_exchanger(int* array_a, int* array_b, int length) {
     // your code
    int i,k;
	 
    for(i=0;i<length;i++){
    	k = * (array_a + i);
    	* (array_a + i) = * (array_b + i);
    	* (array_b + i) = k;
	}
	
}
