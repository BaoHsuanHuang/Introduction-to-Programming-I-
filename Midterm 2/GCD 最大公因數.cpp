// GCD 最大公因數
/*#include <stdio.h>

int x,y;
int gcd(int x,int y);

int main(void)
{
	int ans;
	
	scanf("%d%d",&x,&y);
	
	ans = gcd(x,y);
	printf("%d\n",ans);
	
	return 0;
}

int gcd(int x,int y)
{
	if(y==0) return x;
	else{
		return gcd(y,x%y);
	}

}
*/


// 迴圈版
#include <stdio.h>
int main(void)
{
	int a,b;
	int i;
	
	scanf("%d%d",&a,&b);
	
	for(i=b;i>0;i--){
		if(a%i == 0){
			printf("%d",i);
			return 0;
		}
	}
	
	
	//return 0;
} 



















 
