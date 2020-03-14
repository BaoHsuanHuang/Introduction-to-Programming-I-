#include <stdio.h>

int N;
int q[10];
int valid(int row, int col);
void place(int row);

int count = 0;

int main(void)
{
	scanf("%d",&N);
	
	place(0);
	
	printf("%d",count);
	return 0;
}

int valid(int row,int col)
{
	int i;
	for(i=0;i<row;i++){
		if(q[i] == col || (i-row) == (q[i]-col) || (row-i) == (q[i]-col) ){
			return 0;
		}
	}
 	return 1;		//point
}


void place(int row)
{
	int j;
	if(row >= N){
		count++;
	}else{
		for(j=0;j<N;j++){
			if(valid(row,j)){
				q[row] = j;
				place(row+1);
			}
		}
	}
} 
