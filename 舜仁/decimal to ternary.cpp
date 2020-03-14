#include<stdio.h>
#include<string.h>
int main(void)
{
	int X;
	int i=0,a;
	int str[i];
	
	scanf("%d",&X);
	
	while(X>=3){
		a = X%3;
		str[i] = a;
		X = X/3;
		i++;
	
	}
	
	str[i] = X%3;
	
	for(;i>=0;i--){
		printf("%d",str[i]);
	}
	
	printf("\n");
	
	return 0;
}
