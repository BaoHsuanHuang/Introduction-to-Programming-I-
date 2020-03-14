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

