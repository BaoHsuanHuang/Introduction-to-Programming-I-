#include <stdio.h>
long a,n,p;
long long mod(long, long, long);
int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%ld%ld%ld", &a, &n, &p);
        printf("%lld\n", mod(a%p, n, p));
    }
    return 0;
}
long long mod(long a, long n, long p)
{
    long long ans;
    if(n==0) return 1;
    ans = mod(a, n/2, p);
    if(n%2==0)
        return ans*ans%p;
    else
        return ans*ans%p*a%p;
}
