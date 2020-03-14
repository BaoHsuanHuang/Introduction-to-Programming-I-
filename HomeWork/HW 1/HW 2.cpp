#include <stdio.h>

int main(void)
{
	int N , X , Y , Z , a , b ;
	
	scanf("%d %d %d %d", &N , &X , &Y , &Z);
	
	a = X + Y + Z - N;
	b = X - a;
	
	printf("%d %d",a,b);
	
	return 0;
 } 
