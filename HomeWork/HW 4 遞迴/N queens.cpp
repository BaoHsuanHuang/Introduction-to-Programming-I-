
//¤T®y«°³ù 
#include <stdio.h>

int board[5][5];

void place(int r);
void show_board(void);

void show_board(void)
{
	int i,j;
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			printf("%d",board[i][j]);
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

int valid(int r,int c)
{
	int i;
	for(i=1;i<r;i++){
		if(board[i][c]) return 0;
		else return 1;
	}
}

void place(int r)
{
	int j;
	if(r>3) show_board();
	else{
		for(j=1;j<=3;j++){
		
			if(valid(r,j)){
				board[r][j] = 1;
				place(r+1);
				board[r][j] = 0;
			}
		}
	}
}





//¤K­Ó¬Ó¦Z (¤@ºû°}¦C) 
#include <stdio.h>

int q[10] = {0};
void show(void);
void place(int r);
int valid(int r,int c);
int N;
int count;

void show(void)
{
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(q[i] == j) {
				printf("@");
			}
			else {
				printf("O");
				
			}
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	scanf("%d",&N);
	place(0);
	printf("%d",count);
	return 0;
}

int valid(int r,int c)
{
	int i;
	for(i=0;i<=r-1;i++){    
		if((q[i] == c)|| (r-i == c-q[i]) || (r-i == q[i]-c) ) {
			return 0;
		}
	}
	return 1;
}
		 

void place(int r)
{
	int j;
	if (r >= N){
		show();
		count++;
	}
	else{
		for(j=0;j<N;j++){
			if(valid(r,j)){
				q[r] = j;
				place(r+1);
			}
		}
	}
}



// N ­Ó¬Ó¦Z 
#include <stdio.h>

int q[10] = {0};

void place(int r);
int valid(int r,int c);
int N;
int count;

int main(void)
{
	scanf("%d",&N);
	place(0);
	printf("%d",count);
	return 0;
}

int valid(int r,int c)
{
	int i;
	for(i=0;i<=r-1;i++){    
		if((q[i] == c)|| (r-i == c-q[i]) || (r-i == q[i]-c) ) {
			return 0;
		}
	}
	return 1;
}
		 

void place(int r)
{
	int j;
	if (r >= N){
		count++;
	}
	else{
		for(j=0;j<N;j++){
			if(valid(r,j)){
				q[r] = j;
				place(r+1);
			}
		}
	}
}





 
