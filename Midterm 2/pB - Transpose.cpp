#include <stdio.h>
#include "function.h"

void Transpose( int* row, int* col, int matrix[] [500] ){
	int tmp,a,b;
	int i,j;
	int x;
	
	a = * row;
	b = * col;
	
	tmp = * row;
	* row = * col;
	* col = tmp;	// §â row ©M col ªº­È¤¬´« 
	
	if(b>=a){
		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				if(i<j){
					x = matrix[i] [j];
					matrix[i] [j] = matrix[j] [i];
					matrix[j][i] = x;
				}
			}
		}
	}
	
	else{
		for(i=0;i<a;i++){
			for(j=0;j<a;j++){
				if(i<j){
					x = matrix[i] [j];
					matrix[i] [j] = matrix[j] [i];
					matrix[j][i] = x;
				}
			}
		}
	}

	
}
