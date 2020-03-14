/*#include <stdio.h>

int pow(unsigned long long int,unsigned long long int,unsigned long long int);

int main(void)
{
	int T,i;
	unsigned long long int a,n,p;
	unsigned long long int ans;
	
	for(i=0;i<T;i++){
		scanf("%llu%llu%llu",&a,&n,&p);
		
		ans = pow(a,n,p);
		
		printf("%llu\n",ans);
	}
	
	return 0;
}

unsigned long long int pow(unsigned long long int a , unsigned long long int n , unsigned long long int p)
{
	unsigned long long int ans;
	unsigned long long x;
	
	x = a%p;
	
	if(n%2 == 0){
		ans = pow(x,n/2,p);
		return ((ans%p)*(ans%p))%p;
	}else{
		
	}
	
	return ans;
}
*/

#include<stdio.h>

int main()
{
	long long a,n,p,q,ans=1;
	int t;
	
	scanf("%d",&t);
	
	
	
	while(t--){
		scanf("%lld%lld%lld",&a,&n,&p);
		ans = 1;
		q = a%p;
		for(n;n>=1;n=n/2){
			if (n%2 == 1){
				ans = (ans * q)%p;
			}
			q = (q*q)%p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}


