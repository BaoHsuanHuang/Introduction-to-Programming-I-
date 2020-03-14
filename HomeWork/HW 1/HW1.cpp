#include <stdio.h>

int main(void)
{
	int a , n , d , x , total;
	
	scanf("%d %d %d",&a,&n,&d);
	
	x = a + (n-1)*d;
	total = (2*a + (n-1)*d)*n/2;
	
	printf("%d %d", x , total);
	
	return 0;
	
}
