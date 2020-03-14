// Fibonacci number
#include <stdio.h>
long long f(long long);

int main(void)
{
	long long z;
	scanf("%lld",&z);
	printf("%lld\n",f(z));
	return 0;
 } 

long long f(long long n)
{
	if (n==1){
		return 1;
	}else if (n==2){
		return 1;
	}else{
		return f(n-1)+f(n-2);
	}
}
