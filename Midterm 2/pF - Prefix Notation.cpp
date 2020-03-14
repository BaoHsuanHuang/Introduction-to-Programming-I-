#include <stdio.h>
#include <ctype.h>

float calculate();

int main(void)
{
	float ans;
	
	ans = calculate();
	
	printf("%.3f",ans);
	
	return 0;
}

float calculate()
{
	char c;
	float A,B,ans=0;
	int num;
	
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
		ans = c-'0';
		//return ans;
	}else if(c == '='){
		//return ans;
		ans = calculate();
	}
	return ans;
}
