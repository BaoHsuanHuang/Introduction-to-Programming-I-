#include <stdio.h>
#include <ctype.h>

A + B
+ A B 
// A B 各別都是由一堆運算後得到的值 
// A B 都是由 0~9 和 空格 和 + - * / 組成 

* + 1 2 + 4 + - 5 6 - 7 8	// prefix
(1+2) * ( 4 +((5-6)+(7-8)) ) = 6 	// infix
// A * B
// A = + 1 2
// B = + 4 + - 5 6 - 7 8

int calculate();

int main(void)
{
	// input : * + 1 2 + 4 + - 5 6 - 7 8
	// output : 6
	int ans;
	ans = calculate();
	printf("%d\n",ans);
	
	return 0;
}

int calculate()
{
	int ans;
	char c;
	int A,B;
	
	c = getchar();
	if(isspace(c)) {		// c 為 空白 或 換行\n 或 tab 
		ans = calculate();		// 把前面的 空白 拿掉後答案還是相同 
	}else if (c == '+'){
		A = calculate();		// 一直執行到不合法的地方才停止，傳回 A 
		B = calculate();
		ans = A + B; 
	}else if (c == '-'){
		A = calculate();
		B = calculate();
		ans = A - B; 
	}else if (c == '*'){
		A = calculate();
		B = calculate();
		ans = A * B; 
	}else if (c == '/'){
		A = calculate();
		B = calculate();
		ans = A / B; 
	}else if (isdigit(c)){		// c為數字 	// 但是只會讀一個位數	// 例如 : 18 只會讀到 1 
		//ans = c-'0';
		ungetc(c,stdin);	// 先讀到 1 存進去 c ， 再讀到 8 後發現是 空白 ，再把 1 放回來，得到 18 
		scanf("%d",&ans);		// 再把得到的值一整串存進去 ans 裡面 
	}else {
		ans = 0;
	}
	
	return ans;
}







// infix
int calculate();

int main(void)
{
	// input : * + 1 2 + 4 + - 5 6 - 7 8
	// output : 6
	int ans;
	ans = calculate();
	printf(" = %d\n",ans);
	
	return 0;
}

int calculate()
{
	int ans;
	char c;
	int A,B;
	
	c = getchar();
	if(isspace(c)) {		// c 為 空白 或 換行\n 或 tab 
		ans = calculate();		// 把前面的 空白 拿掉後答案還是相同 
	}else if (c == '+'){
		printf("(");
		A = calculate();		// 一直執行到不合法的地方才停止，傳回 A 
		printf("+");
		B = calculate();
		printf(")");
		ans = A + B; 
	}else if (c == '-'){
		printf("(");
		A = calculate();
		printf("-");
		B = calculate();
		printf(")");
		ans = A - B; 
	}else if (c == '*'){
		printf("(");
		A = calculate();
		printf("*");
		B = calculate();
		printf(")");
		ans = A * B; 
	}else if (c == '/'){
		printf("(");
		A = calculate();
		printf("/");
		B = calculate();
		printf(")");
		ans = A / B; 
	}else if (isdigit(c)){		// c為數字 	// 但是只會讀一個位數	// 例如 : 18 只會讀到 1 
		//ans = c-'0';
		ungetc(c,stdin);	// 先讀到 1 存進去 c ， 在讀到 8 後發現是 空白 ，再把 1 放回來，得到 18 
		scanf("%d",&ans);		// 再把得到的值一整串存進去 ans 裡面 
		printf("%d",ans);
	}else {
		ans = 0;
	}
	
	return ans;
}





