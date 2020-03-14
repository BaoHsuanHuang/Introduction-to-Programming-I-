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
		hanoi(from,buffer,to,n-1);   //�N����buffer=2������n-1�Ӫ��ت��a          //�n�� m steps//
		printf("%d --> %d\n",from,to);
		hanoi(buffer,to,from,n-1);   //���I�O�ܼƦW�٭I��N���Ʀr�A�Ӥ��O�ܼƦW��  //�n�� m steps// 
	}
	// total steps = 2*m + 1 //
}




/*
//�T�y�������D 
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
	place(1);    //�q row 1 �}�l�] 
	return 0;
}

int valid(int r,int c)
{
	int i;
	for (i=1;i<r;i++){
		if(board[i][c]) return 0;     //�N�� false 
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
				board[row][i] = 0;    //�� [row][j] �q�s = 0�A�A�][row][j+1] == 1 ���j�� 
			}
		}
	}
}
*/



/*
//�ӦZ
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
	place(1);    //�q row 1 �}�l�] 
	return 0;
}

int valid(int r,int c)
{
	int i;
	for (i=1;i<r;i++){
		if(board[i][c]) return 0;     //�N�� false 
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
				board[row][i] = 0;    //�� [row][j] �q�s = 0�A�A�][row][j+1] == 1 ���j�� 
			}
		}
	}
} 

*/


/*
//�Q�i����G�i�� 
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
		dec2bin(x/2);     //����� (x/2)���G�i���ܪk 
	
		if(x%2){
			printf("1");
		}else{
			printf("0");
		}
	}
}
*/


/* 
//�`�M 
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


//�`�M 
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



//�O�B�ǫY�ƦC
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

//�O�B�ǫY�ƦC
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





//���ɪO
#include <stdio.h>
#define MAXNV 5
int values[MAXNV];
int numbers[MAXNV];

void show(int nv);
void change(int amount, int smallest, int nv);

int main(void)
{
	int nv, i;   //nv �X�ػɪO 
	int money;

	scanf("%d", &nv);
	if (nv>MAXNV || nv<1) return 0;

	for (i=0; i<nv; i++) {
		scanf("%d", &values[i]);
	}

	scanf("%d", &money);
	change(money, 0, nv);   // �q�s��0 �����ӻɪO���ȶ}�l = values[0] 

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
	if (smallest<nv) {  //smallest : ���ȳ̤p���ɪO�s�� 
		if (amount == 0) {
			show(nv);
		} else if (amount > 0) {
			/* your code here */
			
			change(amount,smallest+1,nv);	// ��N���L�Y�ӭ��Ȫ��ɪO 
			
			numbers[smallest]++;
			change (amount-values[smallest],smallest,nv);
			numbers[smallest]--;
		
		}
	}
}






