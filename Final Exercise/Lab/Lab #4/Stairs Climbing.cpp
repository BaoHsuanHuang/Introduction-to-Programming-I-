#include <stdio.h>

int check(int N);

int count;

int main(void)
{
	int T;
	int N;
	scanf("%d",&T);
	while(T--){
		count = 0;
		
		scanf("%d",&N);
		count = check(N);
		
		printf("%d\n",count);
	}
	return 0;
}

int check(int N)
{
	if(N==1) return 1;
	else if(N==2) return 2;
	else{
		return check(N-1)+check(N-2);
	}
} 
