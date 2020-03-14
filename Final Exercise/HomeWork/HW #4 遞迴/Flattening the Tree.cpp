#include <stdio.h>

int n;
int a[1500];

void flatten(int);

int main(void)
{
	int i;	
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	flatten(1);
	
	
	return 0;
}

void flatten(int k)
{
	if(k == n){
		printf("%d\n",a[k]);
	}
	else if(k<n){
		flatten(2 * k);
		printf("%d ",a[k]);
		flatten(2*k + 1);
	}

}
