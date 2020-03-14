/*#include <stdio.h>
int main(void)
{
	int N,M;
	int str[15];
	int a;
	int i=0;
	int z=0;
	
	scanf("%d",&N);
	M = N+1;
	
	while(M>0){
		a = M%2;
		str[i] = a;
		M = M/2;
		//printf("%d",str[i]);
		i++;		
	}
	
	i = i-1;
	while(i>=0){
		printf("%d",str[i]);
		i--;
	}
	
	i = 0;
	while(str[i] == 0){
		z = z+1;
		i++;
	}
		printf(" %d",z);
	
	return 0;
	
}
*/



#include <stdio.h>
int main(void)
{
	int N,M;
	int i=0;
	int str[15];
	int a,z;
		
	scanf("%d",&N);
	M = N+1;
	
	for(;M>0;M=M/2){
		a = M%2;
		str[i] = a;
		printf("%d",str[i]);
		i = i+1;
	}
	
	printf("\n");
	
	for(i=i-1;i>=0;i--){
		printf("%d",str[i]);
	}
	
	i = 0;
	for(;str[i]==0;){
		z = z+1;
		i++;
	}
	
	printf("\n");
	
	printf("%d",z);
	
	return 0;
}
