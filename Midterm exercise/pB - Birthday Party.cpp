#include <stdio.h>
long long int gcd(long long int n,long long int x);

int main(void)
{
	int T,i;
	long long int n,x1,x2,x3,a,b,c,gcd1,lcm1,gcd2,lcm2,ans;
	
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		scanf("%lld %lld %lld %lld",&n,&x1,&x2,&x3);
		a = gcd(n,x1);
		b = gcd(n,x2);
		c = gcd(n,x3);
		gcd1 = gcd(a,b);
		lcm1 = a/gcd1*b;
		gcd2 = gcd(lcm1,c);
		lcm2 = lcm1/gcd2*c;
		ans = n/lcm2;
		printf("%lld\n",ans);
		
	}
	return 0;
}

long long int gcd(long long int n, long long int x)
{
	if (x==0)
		return n;
	else
		return gcd(x, n%x);
}
 


/*#include <stdio.h>
#include <string.h>
int main(void)
{
	int T,n,a,b,c;
	int i,j,A,k,pony,len_pony,len_pony2;
	char str_A[10],str_B[10],str_C[10],len_a,len_b,len_c;
	char str_pony[10],str_pony2[10];
	
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		scanf("%d%d%d%d",&n,&a,&b,&c);
		
		str_A[0]=a;
		printf("%s\n",str_A[0]);
		for(j=1;;j++){
			str_A[j] = (str_A[j-1]+a)%n;
			if(str_A[j]==0) str_A[j]==n;
			if(str_A[j]==str_A[0]) break;
		}
		printf("%s\n",str_A);
		str_B[0] = (str_A[j]+b)%n;
		for(j=1;;j++){
			str_B[j] = (str_B[j-1]+b)%n;
			if(str_B[j] == str_B[0]) break;
		}
		
		str_C[0] = (str_B[j]+c)%n;
		for(j=1;;j++){
			str_C[j] = (str_C[j-1]+c)%n;
			if(str_C[j] == str_C[0]) break;
		}
		
		len_a = strlen(str_A);
		len_b = strlen(str_B);
		len_c = strlen(str_C);
		printf("%d %d %d",len_a,len_b,len_c);
		
		for(i=0;i<len_a;i++){
			for(j=0;j<len_b;j++){
				if(str_A[i]==str_B[j]){
					pony = str_A[i];
				}
			}
		}
		len_pony = strlen(str_pony);
		//printf("%d\n",len_pony);
		for(i=0;i<len_pony;i++){
			for(j=0;j<len_c;j++){
				if(str_pony[i]==str_C[j]){
					str_pony2[i] = str_pony[i];
				}
			}
		}
		len_pony2 = strlen(str_pony2);
	}
	//printf("%d\n",len_pony2);
	return 0;
}
*/

