#include <stdio.h>

int C,F,H;
int s;
char c;
int y;

char map[21][21];
void up(int row,int col);
void down(int row,int col);

int main(void)
{
	scanf("%d%d%d",&C,&F,&H);
	scanf("%d",&s);
	scanf(" %c",&c);
	
	if(c=='u'){
		map[s][0] = '*';
		up(s,0);
	}else if(c=='d'){
		map[s][0] = '*';
		down(s,0);
	}
	
	if(c>y) y = 
	
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
		y = col+1;
	}else{
		up(row,col);
	}
}
