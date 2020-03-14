#include <stdio.h>
int main(void)
{
	int N;
	int ans;
	scanf("%d",&N);
	
	if(N%3==0 || N%3==1){
		ans = (N/3)*2+1;
	}
	else{
		ans = (N/3)*2+1+1;
	}
	
	printf("%d\n",ans);
	return 0;
}
