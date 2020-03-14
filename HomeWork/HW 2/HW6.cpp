#include <stdio.h>
int main(void)
{
	int N;
	int a,b,c;
	
	scanf("%d",&N);
	a = N/3;
	b = N-a+1;
	c = N-a;
	
	if(N%3 == 0){
		printf("%d\n",b);
	}
	
	else{
		printf("%d\n",c);
	}
	
	return 0;
 } 
