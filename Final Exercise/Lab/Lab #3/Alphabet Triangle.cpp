#include <stdio.h>
int main(void)
{
	char ch;
	int a;
	int i,j;
	
	scanf("%c",&ch);
	
	a = ch-'A';
	
	for(i=0;i<=a;i++){
		
		for(j=a-i;j>0;j--){
			printf(" ");
		}
		
		for(j='A';j<='A'+i;j++){
			printf("%c",j);
		}
		
		for(j='A'+i-1;j>='A';j--){
			printf("%c",j);
		}
		
		for(j=a-i;j>0;j--){
			printf(" ");
		}
		printf("\n");
		
	}

	return 0;
}
