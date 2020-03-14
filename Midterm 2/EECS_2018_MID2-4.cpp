#include <stdio.h>

int map[8][8];
int q[8];
int max = 0;

int place(int row);
int valid(int row,int col);

int main(void)
{
	int T;
	int t;
	int i,j;
	
	scanf("%d",&T);
	for(t=0;t<T;t++){
		
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				scanf("%d",&map[i][j]);
			}
		}
		max = 0;
		place(0);
		
		printf("%d\n",max);
	}
	return 0;
}

int valid(int row,int col)
{
	int i;
	for(i=0;i<row;i++){
		if(q[i]==col || i-row == q[i]-col || i-row == col-q[i]) return 0;
	}
	return 1;
}

int place(int r)
{
	int i,j;
	int count=0;
	
	if(r>=8){
		count = 0;
		for(i=0;i<r;i++){
			count += map[i][q[i]];
		}
		if(count>max) max = count;
		return max;
	}else{
		for(j=0;j<8;j++){
			if(valid(r,j)){
				q[r] = j;
				place(r+1);
			}
		}
	}
}





