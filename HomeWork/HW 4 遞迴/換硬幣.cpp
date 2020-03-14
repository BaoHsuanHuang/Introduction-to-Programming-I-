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

