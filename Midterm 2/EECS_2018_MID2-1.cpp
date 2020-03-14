#include <stdio.h>
#include <ctype.h>

float ans;
char c;

float calculate();

int main(void)
{
	ans = calculate();
	printf("%.3f",ans);
	
	return 0;
}

float calculate()
{
	float A,B;
	c = getchar();
	
	if(c == '+'){
		A = calculate();
		B = calculate();
		ans = A+B;
	}else if(c == '-'){
		A = calculate();
		B = calculate();
		ans = A-B;
	}else if(c == '*'){
		A = calculate();
		B = calculate();
		ans = A*B;
	}else if(c == '/'){
		A = calculate();
		B = calculate();
		ans = A/B;
	}else if(isdigit(c)){
		ans = c - '0';
	}
	
	return ans;
}
