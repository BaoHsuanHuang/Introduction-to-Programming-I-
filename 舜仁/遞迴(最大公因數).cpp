// 遞迴 - 找最大公因數 
#include <stdio.h>
int gcd(int x,int y);
int main(void)
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d",gcd(x,y));
	
	return 0;
} 


int gcd(int x,int y)
{
	int ans;
	
	if(x%y != 0){
		ans = gcd(y,x%y);
	}else return y;
	
	return ans;
} 
