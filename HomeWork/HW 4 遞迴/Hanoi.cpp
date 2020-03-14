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
