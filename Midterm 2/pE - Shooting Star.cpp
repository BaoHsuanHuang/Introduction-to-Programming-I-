#include <stdio.h>
int C,F,H,s;
int x,y;
char c;
char map[21][21];

void up(int row,int col);
void down(int row,int col);

int main(void)
{
	int i,j;
	scanf("%d%d%d",&C,&F,&H);
	scanf("%d",&s);
	scanf(" %c",&c);
	
	if(c == 'u'){
		map[s][0] = '*';
		up(s,0);
	}else{
		map[s][0] = '*';
		down(s,0);
	}
	
	for(i=0;i<C;i++){
		map[0][i] = '-';
	}
	/*for(i=0;i<c;i++){
		printf("%c",map[0][i]);
	}*/
	for(i=0;i<F;i++){
		map[H+1][i] = '-';
	}
	
	if(y<C) y = C-1;
	if(y<F) y = F-1;
	
	for(i=0;i<H+2;i++){
		for(j=0;j<=y;j++){
			if(map[i][j] != '-' && map[i][j] != '*') printf(" ");
			else  printf("%c",map[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}


void up(int row,int col)
{
	if(row>1){
		row--;
		col++;
		map[row][col] = '*';
		up(row,col);
	}else if(col>=C){
		map[row-1][col+1] = '*'; 
		//x = row-1;
		y = col+1;
	}else{
		down(row,col);
	}
}

void down(int row,int col)
{
	if(row<H){
		row++;
		col++;
		map[row][col] = '*';
		down(row,col);
	}else if(col>=F){
		map[row+1][col+1] = '*';
		//x = row+1;
		y = col+1;
	}else{
		up(row,col);
	}
}



