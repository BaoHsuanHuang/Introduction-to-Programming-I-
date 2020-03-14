// prefix to infix
//input : * + 2 3 + 4 + - 5 6 - 7 8
//output : ((2+3)*(4+((5-6)+(7-8))))=10

#include <stdio.h>
#include <ctype.h>

int calculate(void);

int main(void)
{
	int ans;
	
	ans = calculate();
	
	printf("=%d\n",ans);
	
	return 0;
}

int calculate(void)
{
	char c;
	int A,B;
	int ans;
	
	c = getchar();
	
	if(isspace(c)){
		ans = calculate();
	}else if(c == '+'){
		printf("(");
		A = calculate();
		printf("+");
		B = calculate();
		printf(")");
		ans = A+B;
	}else if(c == '-'){
		printf("(");
		A = calculate();
		printf("-");
		B = calculate();
		printf(")");
		ans = A-B;
	}else if(c == '*'){
		printf("(");
		A = calculate();
		printf("*");
		B = calculate();
		printf(")");
		ans = A*B;
	}else if(c == '/'){
		printf("(");
		A = calculate();
		printf("/");
		B = calculate();
		printf(")");
		ans = A/B;
	}else if(isdigit(c)){
		ungetc(c,stdin);
		scanf("%d",&ans);
		printf("%d",ans);
	}	
	return ans;
} 


// Prefix notation






