#include <stdio.h>
int main(void)
{
	int L,Li;
	int i,k;
	int str[100000];
	
	scanf("%d",&L);
	for(i=0;i<L;i++){
		scanf("%d",&str[i]);
	}
	
	printf("..��� ����..\n");
	
	
	for(i=0;i<L;i++){
		for(k=0;k<str[i];k++)
		{
			printf(".");
		}
		printf("����(�i�i�i)����\n");
	}

	return 0;
 } 
