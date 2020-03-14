
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
		hanoi(from,buffer,to,n-1);   //代表此時buffer=2為移動n-1個的目的地          //要做 m steps//
		printf("%d --> %d\n",from,to);
		hanoi(buffer,to,from,n-1);   //重點是變數名稱背後代表的數字，而不是變數名稱  //要做 m steps// 
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








