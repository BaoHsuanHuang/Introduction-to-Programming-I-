#include<stdio.h>
int main(void)
{
	int a,b,c,A,B,d;
	
	scanf("%d%d%d",&a,&b,&c);
	
	if(a+c == 2*b){
		A = 2*a - b;
		B = 2*c - b;
		printf("%d %d",A,B);
	}
	else{
		A = a*a/b;
		B = c*c/b;
		printf("%d %d",A,B);
	}
	return 0;
}
