#include <stdio.h>
int main(void)
{
	int x;
	int a[100];
	
	scanf("%d",&x);
	
	x = x+1;
	
	int i = 0;
	while(x>1){
		a[i] = x%2;
		x = x/2;
		i++;
	}
	a[i] = x;
	
	int k = i;
	int count=0;
	for(;i>=0;i--){
		printf("%d",a[i]);
	}
	int j=0;
	while(a[j]!=1){
		count++;
		j++;
	}
	
	printf(" %d",count);
	return 0;
} 
