#include <stdio.h>

char map[1001][1001];
int m,n;

void check(int x,int y);
int flag = 0;

int main(void)
{
	
	int i,j;
	int x,y;
	
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf(" %c",&map[i][j]);
			if(map[i][j]=='e'){
				x = i;
				y = j;
			}
		}
	}
	
	check(x,y);
	
	if(flag == 1) printf("Alive!\n");
	else printf("Dead!\n");
	
	return 0;
}

void check(int row,int col)
{
	if(map[row][col]=='~') flag = 1;
	else{
		if(row>=0 && row<m && col>=0 && col<n && map[row][col]!='^'){
			if(map[row][col]=='.'){
				check(row-1,col);
				check(row+1,col);
				check(row,col-1);
				check(row,col+1);
			}
			
		}
	}

}
