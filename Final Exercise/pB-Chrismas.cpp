#include <stdio.h>

int main(void)
{
	int T;
	int n;
	int last;
	int ans;
	scanf("%d",&T);
	
	while(T--){
		scanf("%d",&n);
		if(n==1 || n==2 || n==3){
			printf("%d\n",n);
		}else{
			last = n-4;
			ans = 3 + last/2;
			printf("%d\n",ans);
		}
		
	}
	return 0;
} 
