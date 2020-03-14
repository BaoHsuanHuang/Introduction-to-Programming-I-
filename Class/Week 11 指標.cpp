#include <stdio.h>

char str[100]; // 0x10cde3020

int main(void)
{
	//scanf("%s",str);
	printf("%p\n",str);
	
	//long long ss;
	char * ss;	 // ss : 指標(變數) 
	// 指標 = 一個可以用來儲存記憶體位置的變數 
	// (type) * 變數名稱 
	ss = str;	// 記住記憶體的位置 
	//printf("%#llx\n",ss);
	printf("%p\n",ss);
	
	return 0;
}









#include <stdio.h>

char str[100];

int main(void)
{
	scanf("%s",str);
	
	char * ss;
	ss = str;
	
	printf("%s\n",str);
	
	ss++;	// 變成記憶體第二個位置的char 
	*ss = 'Z';	// 改變記憶體位置第一個的char 
	// 不可以直接 str++ ， 因為 str 是一個陣列名稱 
	printf("%s\n",str);
	
	printf("%s\n",str);
	printf("%c\n",str[2]);	== printf("%c\n",ss[2]);  == printf("%c\n",2[str]);
	printf("%c\n",*(ss+2));  == printf("%c\n",*(str+2));  == printf("%c\n",*(2+ss));

	
	// 若 ss = ss + 2
	// 可以 printf("%c\n",str[-2]);  == printf("%c\n",*(ss-2));		// index 可以是負的 
	
	
	return 0;
	
}










#include <stdio.h>
int a[100];
char str[100];

int main(void)
{
	int * ap;
	ap = a;
	
	char * ss;
	ss = str;
	
	printf("%p\n",ap);
	printf("%p\n",ap+1);	// 和 ap 差 4 ， 因為 int 為 4個bytes 
	
	printf("%p\n",ss);
	printf("%p\n",ss+1);	// 和 ss 差 1 ， 因為 char 為 1個bytes 
	
	// double 差 8個bytes 
	
	printf("%ld %ld",sizeof(ss),sizeof(ap));	// 得到皆為 8bytes，因為門牌號碼的大小都是一樣的 
	
	ss++;
	*ss = 'Z';


	
	
	return 0;
}





