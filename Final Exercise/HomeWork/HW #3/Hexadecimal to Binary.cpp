#include <stdio.h>

int main(void)
{
	int x,y;
	int sum;
	int a[100];
	scanf("%x%x",&x,&y);
	
	x = (int)x;
	y = (int)y;
	
	sum = x+y;
	
	//�Q�i�� �� �G�i�� 
	int n=0;
	while(sum>1){
		a[n] = sum%2;
		n++;
		sum = sum/2;
	}
	a[n] = sum;
	
	for(;n>=0;n--){
		printf("%d",a[n]);
	}
	
	return 0;
} 
