#include <stdio.h>
int main(void)
{
	int input;
	int a,b;
	int x,y;
	
	scanf("%d",&input);
	a = input/100;
	b = input%100;
	
	if(a<12)
	{
		printf("%02d:%02d a.m.",a,b);
	}
	
	else
	{
		printf("%02d:%02d p.m.",a-12,b);
	}
	
	return 0;
}
