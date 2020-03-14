
// pA - Matching Point
// 再打一次 
#include <stdio.h>
#include <string.h>
char a[21],b[21];
int la,lb;
int ans;

void check(int i,int j);

int main(void)
{
	int i,j;
	ans = 0;
	while(scanf("%s",a) != EOF && scanf("%s",b) != EOF){
		la = strlen(a);
		lb = strlen(b);
		
		//for(i=0;i<la;i++){
		//	if(a[i] == b[0]){
		//		check(i,0);
		//	}
		//}
		check(0,0);			// point
		
		printf("%d\n",ans);
		ans = 0;
	}
}

void check(int i,int j)
{
	int k;
	if(j == lb){
		ans++;
	}
	else{
		for(k=i;i<la;i++){
			if(a[i] == b[j]){
				check(i+1,j+1);
			}
		}
	}
}





// pB - Transpose
// 再打一次 
void Transpose( int* row, int* col, int matrix[][500] )
{
	int tmp;
	int i,j;
	int t[500][500];
	
	for(i=0 ; i<*col ; i++){
		for(j=0;j<*row;j++){
			t[i][j] = matrix[j][i];
		}
	}
	for(i=0;i<*col;i++){
		for(j=0;j<*row;j++){
			matrix[i][j] = t[i][j];
		}
	}
	
	tmp = *row;
	*row = *col;
	*col = tmp;
}







// pC - Ponds 
#include <stdio.h>

char map[1001][1001];
int m,n;
int ans;

void check(int i,int j);

int main(void)
{
	int i,j;
	
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		while(getchar() != '\n');
		for(j=0;j<n;j++){
			scanf("%c",&map[i][j]);
			if(map[i][j]=='~') map[i][j] = 1;		// point
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(map[i][j] == 1){
				//map[i][j] = 1;
				check(i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	
	return 0;
}

void check(int i,int j)
{
	if(i>=0 && i<m && j>=0 && j<n){
		if(map[i][j] == 1){
			map[i][j] = 0;
			check(i-1,j);
			check(i,j-1);
			check(i+1,j);
			check(i,j+1);
		}
	}
}









// pD - Fire
#include <stdio.h>

char map[1001][1001];
int m,n;
int flag=0;

void check(int i,int j);

int main(void)
{
	int i, j ;
	int x,y;
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		while(getchar() != '\n');
		for(j=0;j<n;j++){
			scanf("%c",&map[i][j]);
			if(map[i][j] == 'e'){
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

void check(int i,int j)
{
	if(i>=0 && i<m && j>=0 && j<n && map[i][j] != '^' && flag==0){
		if(map[i][j]=='~'){
			flag = 1;
		}else{
			map[i][j] = '^';
			check(i-1,j);
			check(i,j-1);
			check(i+1,j);
			check(i,j+1);
		}
	}
}









// pE - Shooting Star
#include <stdio.h>

int c,f,h,s;
char dir;
char map[21][21];
int y;

void up(int row,int col);
void down(int row,int col);

int main(void)
{
	int i,j;
	
	scanf("%d%d%d",&c,&f,&h);
	scanf("%d",&s);
	scanf(" %c",&dir);
	
	map[s][0] = '*';
	
	for(i=0;i<c;i++){
		map[0][i] = '-';
	}
	for(i=0;i<f;i++){
		map[h+1][i] = '-';
	}
	
	if(dir=='u') up(s,0);
	else down(s,0);
	
	if(c-1>y) y = c-1;
	if(f-1>y) y = f-1;
	
	for(i=0;i<h+2;i++){
		for(j=0;j<=y;j++){
			if(map[i][j] != '-' && map[i][j] != '*') printf(" ");
			else printf("%c",map[i][j]);
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
	}else if(col>=c){
		map[row-1][col+1] = '*';
		y = col+1;
	}else{
		down(row,col);
	}
}

void down(int row,int col)
{
	if(row<h){
		row++;
		col++;
		map[row][col] = '*';
		down(row,col);
	}else if(col>=f){
		map[row+1][col+1] = '*';
		y = col+1;
	}else{
		up(row,col);
	}
}


