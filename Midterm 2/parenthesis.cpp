/*用 recursive 方式，產生下面的輸出
Input: 10 
Output: ((((1+2)*3+4)*5+6)*7+8)*9+10=4555 
Input: 11 
Output: (((((1+2)*3+4)*5+6)*7+8)*9+10)*11=50105
*/
#include <stdio.h>
void show_parenthesis(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    show_parenthesis(n);
    return 0;
}

void show_parenthesis(int n)
{
    // your code
    int ans;
    if(n>1){
   	    if(n%2 == 0){
   	 		//printf("(");
    		show_parenthesis(n-1);
    		printf("+%d)",n);
    		ans = ans + n;
		}
		
		if(n%2 == 1){
			printf("(");
			show_parenthesis(n-1);
			ans = ans * n;
		}
	}
	if(n==1){
		printf("%d",n);
		ans = ans+1;
	}
	printf("%d\n",ans);
}



