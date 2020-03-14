#include <stdio.h>
int main(void)
{
	int X,Y;
	int a,b,c;
	int n;
	int str[1000],i,j;
	
	scanf("%x%x",&X,&Y);
	
	a = (int)X;
	b = (int)Y;
	c = a+b;
	
	i = 0;
	j = 0;
	while (c>1){
		n = c%2;
		str[i] = n;
		c = c/2;
		i++;
	}
	if (c==1){
		str[i] = c;
	}
	
	for(;i>=0;i--){
		printf("%d",str[i]);
	}
	
	
	return 0;
} 
