#include <stdio.h>
#include <ctype.h>

A + B
+ A B 
// A B �U�O���O�Ѥ@��B���o�쪺�� 
// A B ���O�� 0~9 �M �Ů� �M + - * / �զ� 

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
	if(isspace(c)) {		// c �� �ť� �� ����\n �� tab 
		ans = calculate();		// ��e���� �ť� �����ᵪ���٬O�ۦP 
	}else if (c == '+'){
		A = calculate();		// �@������줣�X�k���a��~����A�Ǧ^ A 
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
	}else if (isdigit(c)){		// c���Ʀr 	// ���O�u�|Ū�@�Ӧ��	// �Ҧp : 18 �u�|Ū�� 1 
		//ans = c-'0';
		ungetc(c,stdin);	// ��Ū�� 1 �s�i�h c �A �AŪ�� 8 ��o�{�O �ť� �A�A�� 1 ��^�ӡA�o�� 18 
		scanf("%d",&ans);		// �A��o�쪺�Ȥ@���s�i�h ans �̭� 
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
	if(isspace(c)) {		// c �� �ť� �� ����\n �� tab 
		ans = calculate();		// ��e���� �ť� �����ᵪ���٬O�ۦP 
	}else if (c == '+'){
		printf("(");
		A = calculate();		// �@������줣�X�k���a��~����A�Ǧ^ A 
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
	}else if (isdigit(c)){		// c���Ʀr 	// ���O�u�|Ū�@�Ӧ��	// �Ҧp : 18 �u�|Ū�� 1 
		//ans = c-'0';
		ungetc(c,stdin);	// ��Ū�� 1 �s�i�h c �A �bŪ�� 8 ��o�{�O �ť� �A�A�� 1 ��^�ӡA�o�� 18 
		scanf("%d",&ans);		// �A��o�쪺�Ȥ@���s�i�h ans �̭� 
		printf("%d",ans);
	}else {
		ans = 0;
	}
	
	return ans;
}





