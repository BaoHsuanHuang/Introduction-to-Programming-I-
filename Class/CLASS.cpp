#include <stdio.h>
#include <string.h>    //string.h 字串的函數   //char array : 字元陣列 
#define AMY 123.45678  //先定義好AMY 
int main(void)
{
	char x;
	
	x = 'A' ;
	//若x = '7' 並不是代表數字7，而是字元 
	//x不能等於560  因為char的範圍:-128~127(8位元) 
	printf("%d",x);   //show 65(二進位為1000001) 
	printf("%c",x);
	printf("%#x",x);  //16進位表示字元A的數值 
	
	x = '7';
	printf("%c",x-'0');  //'7' - '0'代表 55-48
	
	scanf("%c",&x); //scanf可搭配 %c(但很少用) 
	//若輸入 7 代表的是字元(%c)
	
	
	char name[10];
	scanf("%s",name);  //char的scanf 規則(name本身的意義就是一個空間、所以不用加&) 
	printf("%s",name); //%s是字元串   //記憶體中的整數值 0 再配上 %s 代表結束 
	printf("%c",name[2]); // %c show 出單一特定字元(name[2])
	//name[0].name[1].....從0開始
	printf("%p",name);  //show出name在記憶體的位置
	printf("%p",&name[1]); //需要加 & 
	
	//記憶體中的整數值 0 再配上 %s 代表結束 
	scanf("%s",name);  //輸入Tommy 
	name[2] = 0; 或是 name[2] = '\0'; 
	printf("%s",name);  //只會輸出Tom
	
	printf("the length of %s is %d",name,strlen(name));
	printf("the number of characters in %s is %d",name,strlen(name));  //若字元數很長，可用 %u(unsigned int) 
	
	scanf("%9s",name);  //可以限制輸入的字元數 
	
	#define border "##########################"  //define 用 ""代表雙引號內是字元 
	cahr word[26];
	scanf("%25s",word);
	printf("") 看手機的photo 
	
	
	printf("%s %s\n",__DATE__,__TIME__);
	printf("%s %s %d\n",__func__,__FILE__.__LINE__);
	
	return 0;
 } 
