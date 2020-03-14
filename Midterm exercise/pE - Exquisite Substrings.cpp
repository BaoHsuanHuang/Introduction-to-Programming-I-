#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[3000];
	int length,i,j,k,count = 0;
	
	while(scanf("%s",str) != EOF){
		length = strlen(str);
		count = 0;
		for(i=0;i<length;i++){
			for(j=i-1,k=i+1;j>=0 && k<length;j--,k++){
				if(str[j] == str[k]) count++;
				else break;		// point
			}
			for(j=i,k=i+1;j>=0 && k<length;j--,k++){
				if(str[j] == str[k]) count++;
				else break;		// point
			}
		}
	printf("%d\n",count);
		
	}
	return 0;
} 
