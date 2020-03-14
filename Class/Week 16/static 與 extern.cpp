/*
static

函數前面如果加 static 
表示這個函數不會被 linker 看到
因此不會和其他檔案連結

變數前面如果加 static
表示這個變數從程式開始執行就會存在
直到程式結束才會消失

extern

只在一個原始碼檔案中定義
int x = 0;
其他原始碼檔案如果使用 x，應該宣告成
extern int x
*/
#include <stdio.h>
#include <stdlib.h>
int f(void)
{
	static int x=0;
	x = x+1;
	return x;
}

int main(void)
{
	printf("%d\n",f());
	printf("%d\n",f());
	printf("%d\n",f());
	printf("%d\n",f());
	printf("%d\n",f());
	
	return 0;
}
