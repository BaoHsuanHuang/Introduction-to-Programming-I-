#include <stdio.h>

void check(int row,int col);
int m,n;
char map[1000][1000];

int main(void)
{
	int i,j;
	int count=0;
	
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf(" %c",&map[i][j]);		//point  ­nª`·N '\n' 
			if(map[i][j]=='~') map[i][j] = 1;
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(map[i][j]==1){
				check(i,j);
				count++;
			}
		}
	}
	
	printf("%d\n",count); 
	
	return 0;
}

void check(int row,int col)
{
	if(row>=0 && row<m && col>=0 && col<n ){		
		if(map[row][col]==1){
			map[row][col] = 0;
		
			check(row-1,col);
			check(row+1,col);
			check(row,col-1);
			check(row,col+1);
		}
	}
	
}
