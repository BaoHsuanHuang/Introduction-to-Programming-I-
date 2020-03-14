/*
// N queens
#include <stdio.h>
#define NQ 6

/* q[i] �O�����O�b�� i �C (row) �X�{���ӦZ�A�n�\�b�ĴX�� (column) */
/* Ĵ�p�Aq[] �����e�p�G�O {2, 0, 3, 1}�A��ܥ|�ӬӦZ���O��b�ѽL�� (0,2), (1,0), (2,3), (3,1) �|�Ӧ�m */
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
�P�_�ثe�����p�U�A�p�G�b row, col ��m��J�s���ӦZ
�O�_�|�M���e���ӦZ�Ĭ�
�p�G�O�X�k����m�覡 return 1;
�p�G���Ĭ� return 0;
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
// �T�y����
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

	scanf("%d", &nv);	// nv : ���X�ع��� 
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
