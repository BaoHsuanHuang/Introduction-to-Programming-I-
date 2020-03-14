
// pA - Matching Point
#include <stdio.h>
#include <string.h>
char a[21],b[21];
int la,lb;
int count;

void check(int now,int pos);

int main(void)
{
	while(scanf("%s",a) != EOF && scanf("%s",b) != EOF){
		la = strlen(a);
		lb = strlen(b);
		
		check(0,0);
		
		printf("%d\n",count);
		count = 0;
	}
	return 0;
}

void check(int now,int pos)
{
	int i;
	if(pos == lb){
		count++;
	}else{
		for(i=now;i<la;i++){
			if(a[i] == b[pos]){
				check(i+1,pos+1);
			}
		}
	}
}










// pB - Transpose
void Transpose( int* row, int* col, int matrix[][500] )
{
	int tmp;
	int t[500][500];
	int i,j;
	
	for(i=0;i<*col;i++){
		for(j=0;j<* row ;j++){
			t[i][j] = matrix[j][i];
		}
	}
	
	for(i=0;i<*col;i++){
		for(j=0;j<*row;j++){
			matrix[i][j] = t[i][j];
		}
	}
	
	tmp = * row;
	*row = * col;
	* col = tmp;
}








// pE - Shooting Star 




















// Lab 5 : more simple exercise of pointer on array
#include <stdio.h>
#include "function.h"
void array_exchanger(int* array_a, int* array_b, int length) {
     // your code
     int i;
     int tmp;
     
     for(i=0;i<length ;i++){
     	tmp = * (array_a + i);
     	* (array_a + i) = * (array_b + i);
     	* (array_b + i) = tmp;
	 }
	 
}






// Lab 5 : pC - Ponds
#include <stdio.h>

int m,n;
char map[1001][1001];
int count;

void check(int i,int j);

int main(void)
{
	int i,j;
	
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		while(getchar() != '\n');
		for(j=0;j<n;j++){
			scanf("%c",&map[i][j]);
			if(map[i][j] == '~'){
				map[i][j] = 1;
			}
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

void check(int i,int j)
{
	if(i>=0 && i<m && j>=0 && j<n){
		if(map[i][j]==1){
			map[i][j] = 0;
			check(i-1,j);
			check(i,j-1);
			check(i+1,j);
			check(i,j+1);
		}
	}
}








// Lab 5 : Fire!!!!!!!
#include <stdio.h>

int m,n;
char map[1001][1001];
int x,y;
int flag = 0;

void check(int i,int j);

int main(void)
{
	int i,j;
	
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
		if(map[i][j] == '~'){
			flag = 1;
		}
		else{
			map[i][j] = '^';
			check(i-1,j);
			check(i,j-1);
			check(i+1,j);
			check(i,j+1);
		}
	}
}








// Lab 4 : Stairs Climbing
#include <stdio.h>
int check(int x);

int ans=0;

int main(void)
{
	int T,N;
	int t;
	
	scanf("%d",&T);
	for(t=0;t<T;t++){
		
		scanf("%d",&N);
		
		ans = 0;
		//ans = check(N-1) + check(N-2);
		ans = check(N);
		
		printf("%d\n",check(N));
			
	}
	return 0;
}

int check(int x)
{
	if(x == 1){
		ans = 1;
	}else if(x == 2){
		ans = 2;
	}else{
		ans = check(x-1) + check(x-2);
	}
	return ans;
	
	
	//if(x == 1) return 1;
	//else if(x == 2) return 2;
	//else return check(x-1) + check(x-2);

}







/*
// Lab 4 : Flattening the Tree v2 - Preorder Traversal
#include <stdio.h>

int a[1025];
int n;

void check(int k);

int main(void)
{
	int i;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	check(1);
	
	return 0;
}

void check(int k)
{
	if(k<n){
		printf("%d ",a[k]);
		check(2*k);
		check(2*k+1);
	}
	if(k==n){
		printf("%d\n",a[k]);
	}

}
*/








// HW 4 : N queens
#include <stdio.h>

int n;
int q[10];
int count = 0;

void place(int r);
int valid(int row,int col);

int main(void)
{
	scanf("%d",&n);
	
	place(1);
	
	printf("%d",count);
	return 0;
}

int valid(int row,int col)
{
	int i;
	for(i=1;i<row;i++){
		if(q[i] == col || i-row == q[i]-col || i-row == col-q[i]) return 0;
	}
	return 1;

}

void place(int r)
{
	int i,j;
	if(r>n) count++;
	//for(i=1;i<=n;i++){
	else{
		for(j=1;j<=n;j++){
			if(valid(r,j)){
				q[r] = j;
				//count++;
				place(r+1);
			}
		}
	}
	//return count;
}









// HW 4 : Fill containers with water
#include <stdio.h>
#define MAXNV 5
int DONE = 0;
int liters[MAXNV];
int numbers[MAXNV];
void show(int nv);
void filling(int amount, int cur, int nv);
int j=0;
int water;
int min=100;
int min_numbers[MAXNV]={0};
int main(void)
{
    int nv, i;

    scanf("%d", &nv);
    for (i=0; i<nv; i++) {
        scanf("%d", &liters[i]);
    }
    scanf("%d", &water);
    filling(water, 0, nv);

    for(i=0;i<nv;i++)
        numbers[i]=min_numbers[i];
    show(nv);
    return 0;
}

void show(int nv)
{
    int i;
    printf("(%d", numbers[0]);
    for (i=1; i<nv; i++) {
        printf(",%d", numbers[i]);
    }
    printf(")\n");
}

void filling(int amount, int cur, int nv)
{
    // your code 
    int count=0;
    int i;
    
    if(cur<nv){
    	if(amount==0){
    		count = 0;
    		for(i=0;i<nv;i++){
    			count += numbers[i];
			}
			if(count<min){
				min = count;
				for(i=0;i<nv;i++){
					min_numbers[i] = numbers[i];
				}
			}
		}
		if(amount>0){
			filling(amount,cur+1,nv);
		
			numbers[cur]++;
			filling(amount-liters[cur],cur,nv);
			numbers[cur]--;
		}	
	}
}









// «°³ù 
#include <stdio.h>

int board[5][5];
void place(int row);
void show_board(void)
{
	int i, j;
	for (i=1; i<=3; i++) {
		for (j=1; j<=3; j++) {
			printf(" %d", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(void)
{
	place(1);
	return 0;
}
int valid(int row, int col)
{
    int i;
    for (i=1; i<row; i++) {
        if (board[i][col]) return 0;
    }
    return 1;
}
void place(int row)
{
	int i;
	if (row>3) {
		show_board();
	} else {
		for (i=1; i<=3; i++) {
		    if (valid(row, i)) {
			    board[row][i] = 1;
			    place(row+1);
			    board[row][i] = 0;
			}
		}
	}
}








