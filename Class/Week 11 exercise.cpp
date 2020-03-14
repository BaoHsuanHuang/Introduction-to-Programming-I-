// 只計算答案 不顯示括號
#include <stdio.h>
#include <ctype.h>

//* + 2 3 + 4 + - 5 6 - 7 8

int calculate(void);

int main(void)
{
	printf("%d\n",calculate());
	return 0;
}

int calculate(void)
{
	int ans;
	int c;
	int A,B;
	
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
		printf("%d",ans);	// point
	}
	
	
	return ans;
}
















/*#include <stdio.h>
int main(void)
{
	char str[100]={0};
	
	scanf("%s",str);
	//printf("%s",str);
	
	char * ss;
	ss = str;
	
	*ss = 'Z';
	
	printf("%s",str); 
	
	return 0;
}
*/ 
