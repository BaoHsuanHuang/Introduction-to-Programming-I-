#include <stdio.h>

void f(int *);

int main(void)
{
	int x;
	scanf("%d",&x);
	printf("%d\n",x);
	
	f(&x);		// 傳遞 位置給 f function 
	
	printf("%d\n",x);
	
	return 0;
}

void f(int * xp)	// xp = &x
{
	*xp = *xp + 1;
}


// __func__ : 會被所在函式給取代 ( ex. main function ) 
// __LINE__ : 代表行號(第幾行) ( 用 %d ) 
// __TIME__ : show 當時執行的時間 








#include <stdio.h>

unsigned int mylen(char *);

void f(int *);

int main(void)
{
	int x;
	char str[100];
	int a[100];
	
	scanf("%s",str);
	printf("%s\n",str);
	
	printf("%u\n",mylen(str));
	
	return 0;
}

unsigned int (char * cp);
{
	unsigned int len = 0;
	while (*cp != '\0'){
		cp++;	 // 跳到下一個位置 
		len++
	}
	
	return len;
}
// 改寫 1
unsigned int mylen(char * cp)
{
	char *  startp;		// 宣告 startp 為一 char的指標變數 
	startp = cp;
	
		while (*cp != '\0'){
		cp++;	 // 跳到下一個位置 
	}
	
	return cp-startp;
	
} 
// 改寫 2
unsigned int mylen(char * cp)
{
	unsigned int len = 0;
	
	while ( cp[len] != '\0'){	// cp[lne] --> *(cp+len) 等價 
		len++;	 // 跳到下一個位置 
	}
	
	return len;
	
} 
// 要注意 char 陣列是用 '\0' 結尾 







#include <stdio.h>

int sum(int *,int);

int main(void)
{
	int n,x,i;
	int a[100];
	char *cp;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);	// &a[i]  -->  a+i
		// 原理 : &a[i]  -->  & *(a+i)  -->  a+i 	// & 和 * 互相抵銷 
	}
	
	cp = (char *) a;	// 強制轉換型別 	// 就可以分別印出 int 裡 4個 bytes 的值 
	printf("%d %d %d %d\n",cp[0],cp[1],cp[2],cp[3]);
	
	printf("%d\n",sum(a,n));
	
	return 0;
} 

int sum(int * xp,int n)
{
	int ans;
	
	while(n>0){
		ans = ans + *xp;
		xp++;
		n--;
	}
	return ans;
}
//改寫
int sum(int b[],int n)
{
	int i,ans;
	for(i=0,ans=0;i<n;i++){
		ans += b[i];	//	b[i]  -->  *b
	}
	
	return ans;
}







#include <stdio.h>

int main(void)
{
	int x;
	
	int *   xp;

	/*	初始化:
	xp = &x;	*/ 

	*xp = 100;		// 有問題 : 因為尚未初始化(還不知道 xp 到底在哪裡)就去改變它的值 --> 有可能會當掉 
	
	return o;
} 












