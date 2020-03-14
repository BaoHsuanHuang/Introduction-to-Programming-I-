#include <stdio.h>
int main(void)
{
	int time;
	int i;

	int a,b;
	scanf("%d",&time);
	
	a = time/100;
	b = time%100;

	
	if(a>=12){
		a = a-12;
		printf("%02d:%02d p.m.",a,b);		//point : %02d
	}
	else{
		printf("%02d:%02d a.m.",a,b);
	}
	
	return 0;
}
