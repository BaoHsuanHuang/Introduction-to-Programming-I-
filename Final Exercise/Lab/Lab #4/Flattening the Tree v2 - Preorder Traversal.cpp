#include <stdio.h>

void flatten(int i);
int A[1000];
int n;

int main(void)
{	
	int i;
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	
	flatten(1);
	
	return 0;
}

void flatten(int k)
{
	if(k==n){
		printf("%d\n",A[n]);
	}else if(k<n){
		printf("%d ",A[k]);
		flatten(2*k);
		flatten(2*k+1);		
	}
}
