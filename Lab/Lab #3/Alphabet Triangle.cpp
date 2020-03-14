#include <stdio.h>
int main(void)
{
	int i,A,j,k,m;
	int ch;
	
	ch = getchar();
	A = ch-(int)'A';
	for(i=0;i<=A;i++){
		for(j=i;j<A;j++){
			printf(" ");
		}
		for(k='A';k<i+'A';k++){
			putchar(k);
		}
		for(;k>='A';k--){
			putchar(k);
		}
		for(j=i;j<A;j++){
			printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
