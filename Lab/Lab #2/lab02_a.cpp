#include <stdio.h>
int main(void)
{
	int i;
	int str[10];
	int sum;
	
	for (i=1;i<=9;i++){
		scanf("%d",&str[i]);
	}
	
	i = 1;
	sum = 0;
	
	while (str[i] != 1){
		sum = sum +str[i];
		i = str[i];
	}
	
	sum = sum + 1;
	printf("%d\n",sum);
	
	return 0;
 } 
