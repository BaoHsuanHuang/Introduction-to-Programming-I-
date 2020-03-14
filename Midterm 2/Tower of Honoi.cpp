
// Tower of Honoi
#include <stdio.h>
void hanoi(int from,int to,int buffer,int n);

int main(void)
{
	hanoi(1,3,2,3);
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


#include <stdio.h>
void hanoi(int n, char from_A, char buffer_B, char to_C);

int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

void hanoi(int n,char from_A,char buffer_B,char to_C)
{
	if(n>0){
		hanoi(n-1,from_A,to_C,buffer_B);
		printf("%d\n",n);
		hanoi(n-1,buffer_B,from_A,to_C);
	}
}








