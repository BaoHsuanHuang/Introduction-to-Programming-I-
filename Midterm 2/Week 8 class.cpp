/*
// N queens
#include <stdio.h>
#define NQ 6

/* q[i] 記錄的是在第 i 列 (row) 出現的皇后，要擺在第幾行 (column) */
/* 譬如，q[] 的內容如果是 {2, 0, 3, 1}，表示四個皇后分別放在棋盤的 (0,2), (1,0), (2,3), (3,1) 四個位置 */
/*
int q[NQ] = {0};
int count=0;

void place(int row);
int valid(int row, int col);
void display(void);

int main(void)
{
	place(0);
	printf("%d\n",count);
	return 0;
}
*/
/*
判斷目前的狀況下，如果在 row, col 位置放入新的皇后
是否會和之前的皇后衝突
如果是合法的放置方式 return 1;
如果有衝突 return 0;
*/
/*
int valid(int row, int col)
{
	int i;
	for (i=0; i<=row-1; i++) {
		if(q[i]==col || row-i == col-q[i] || row-i == q[i]-col){
			return 0;
		}
	}
	return 1;
}

void display(void)
{
	int i,j;
	for(i=0;i<NQ;i++){
		for(j=0;j<NQ;j++){
			if(q[i]==j) printf("@");
			else printf("O");
		}
		printf("\n");
	}
	printf("\n");
}

void place(int row)
{
	int j;
	if (row == NQ) {
		display();
		count++;
	} else {
		for (j=0; j<NQ; j++) {
			if (valid(row, j)) {
				q[row] = j;
				place(row+1);
			}
		}
	}
}
*/









/*
// 三座城堡
// question 
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
void place(int row)
{
	int i;
	if (row>3) {
		show_board();
	} else {
		for (i=1; i<=3; i++) {
			board[row][i] = 1;
			place(row+1);
			board[row][i] = 0;
		}
	}
}
*/










// Make Change
#include <stdio.h>
#define MAXNV 5
int values[MAXNV];
int numbers[MAXNV];

void show(int nv);
void change(int amount, int smallest, int nv);

int main(void)
{
	int nv, i;
	int money;

	scanf("%d", &nv);	// nv : 有幾種幣值 
	if (nv>MAXNV || nv<1) return 0;

	for (i=0; i<nv; i++) {
		scanf("%d", &values[i]);
	}

	scanf("%d", &money);
	change(money, 0, nv);

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
	if (smallest<nv) {
		if (amount == 0) {
			show(nv);
		} else if (amount > 0) {
			/* your code here */
			change(amount,smallest+1,nv);
			numbers[smallest]++;
			change(amount-values[smallest],smallest,nv);
			numbers[smallest]--;

		}
	}
}
