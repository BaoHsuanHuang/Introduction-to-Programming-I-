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
