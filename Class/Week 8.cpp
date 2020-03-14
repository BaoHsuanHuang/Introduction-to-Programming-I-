/*#include<stdio.h>
int main(void)
{
	char ch;
	while(scanf("%c",&ch) != EOF){
		printf("%c\n",ch);
		while(getchar() != '\n');
	}
	return 0;
} 
*/




//Tower of Hanoi
//rewrite on my own
#include <stdio.h>
void hanoi(int from,int to,int buffer,int n);

int main(void)
{
	hanoi(1,3,2,4);
	return 0;
}

void hanoi(int from,int to,int buffer,int n)
{
	if(n>0){
		hanoi(from,buffer,to,n-1);   //代表此時buffer=2為移動n-1個的目的地          //要做 m steps//
		printf("%d --> %d\n",from,to);
		hanoi(buffer,to,from,n-1);   //重點是變數名稱背後代表的數字，而不是變數名稱  //要做 m steps// 
	}
	// total steps = 2*m + 1 //
}




/*
//三座城堡問題 
#include <stdio.h>

int board[5][5];
void place(int row);
void show_board (void);

void show_board(void)
{
	int i, j;
	for (i=1; i<=3; i++) {
		for (j=1; j<=3; j++) {
			printf("%d", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	place(1);    //從 row 1 開始跑 
	return 0;
}

int valid(int r,int c)
{
	int i;
	for (i=1;i<r;i++){
		if(board[i][c]) return 0;     //代表 false 
	}
	return 1;
}

void place(int row)
{
	int i,j;
	if (row>=3) {
		show_board();
	} else {
		for (i=1; i<=3; i++) {
			if(valid(row,j)){
				board[row][i] = 1;
				place(row+1);
				board[row][i] = 0;    //讓 [row][j] 從新 = 0，再跑[row][j+1] == 1 的迴圈 
			}
		}
	}
}
*/



/*
//皇后
#include <stdio.h>
#define size 4
int q[size];
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
	place(1);    //從 row 1 開始跑 
	return 0;
}

int valid(int r,int c)
{
	int i;
	for (i=1;i<r;i++){
		if(board[i][c]) return 0;     //代表 false 
	}
	return 1;
}

void place(int row)
{
	int i,j;
	if (row>3) {
		show_board();
	} else {
		for (i=1; i<=3; i++) {
			if(valid(row,j)){
				board[row][i] = 1;
				place(row+1);
				board[row][i] = 0;    //讓 [row][j] 從新 = 0，再跑[row][j+1] == 1 的迴圈 
			}
		}
	}
} 

*/


/*
//十進位轉二進位 
#include <stdio.h>

void dec2bin(int x);

int main(void)
{
	int z;
	while(scanf("%d",&z) == 1){
		dec2bin(z);
		printf("\n");
	}
	return 0;
}

void dec2bin(int x)
{
	if(x>0){
		dec2bin(x/2);     //先顯示 (x/2)的二進位表示法 
	
		if(x%2){
			printf("1");
		}else{
			printf("0");
		}
	}
}
*/


/* 
//總和 
#include <stdio.h>

long long f(long long x);

int main(void)
{
	int z;
	scanf("%d",&z);
	printf("%lld\n",f(z));
	return 0;
}

long long f(long long x)
{
	int ans;
	if(x>0){
		ans = x + f(x-1);
	}else{
		ans = 0;
	}
	return ans;
 } 


//總和 
//tail recursion
#include <stdio.h>

long long f(long long x,long long ans);

int main(void)
{
	long long z;
	scanf("%lld",&z);
	printf("%lld\n",f(z,0));
	return 0;
}

long long f(long long x,long long ans)
{
	
	if(x>0){
		return f(x-1,ans+x);
	}else{
		return ans;
	}
 }
*/



//費伯納係數列
#include <stdio.h>
long long f(long long);

int main(void)
{
	long long z;
	scanf("%lld",&z);
	printf("%lld\n",f(z));
	return 0;
 } 

long long f(long long n)
{
	if (n==1){
		return 1;
	}else if (n==2){
		return 1;
	}else{
		return f(n-1)+f(n-2);
	}
}

//費伯納係數列
//tail recursion
#include <stdio.h>
long long f(long long,long long,long long);

int main(void)
{
	long long z;
	scanf("%lld",&z);
	printf("%lld\n",f(z,1,0));
	return 0;
 } 

long long f(long long n,long long a,long long b)
{
	if (n==1){
		return a;
	}else{
		return f(n-1,a+b,a);
	}
}





//換銅板
#include <stdio.h>
#define MAXNV 5
int values[MAXNV];
int numbers[MAXNV];

void show(int nv);
void change(int amount, int smallest, int nv);

int main(void)
{
	int nv, i;   //nv 幾種銅板 
	int money;

	scanf("%d", &nv);
	if (nv>MAXNV || nv<1) return 0;

	for (i=0; i<nv; i++) {
		scanf("%d", &values[i]);
	}

	scanf("%d", &money);
	change(money, 0, nv);   // 從編號0 的那個銅板面值開始 = values[0] 

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

void change(int amount, int smallest, int nv)
{
	if (smallest<nv) {  //smallest : 面值最小的銅板編號 
		if (amount == 0) {
			show(nv);
		} else if (amount > 0) {
			/* your code here */
			
			change(amount,smallest+1,nv);	// 刻意跳過某個面值的銅板 
			
			numbers[smallest]++;
			change (amount-values[smallest],smallest,nv);
			numbers[smallest]--;
		
		}
	}
}






