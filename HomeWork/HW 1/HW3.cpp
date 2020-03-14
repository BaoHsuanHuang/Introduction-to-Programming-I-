#include <stdio.h>

int main(void)
{
	double N;
	double M;
	double total;
	int x;
	int a,b,c,d,e,f;
	
	scanf("%lf",&N);
	x = N*1000;
	a = x/100000;
	b = (x/10000)%10;
	c = (x/1000)%10;
	d = (x/100)%10;
	e = (x/10)%10;
	f = x%10;
	
	M = (c*100 + b*10 + a + f*0.1 + e*0.01 + d*0.001);
	
	total = M + N;
	printf("%.3lf",total);
	//printf("%d %d %d %d %d %d",a,b,c,d,e,f);
	return 0;
 } 
