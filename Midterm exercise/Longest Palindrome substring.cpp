#include <stdio.h>
#include <string.h>

int main(void)
{
	int N,i,length,j,k,center,max,count=0;
	char str[10000];
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		max=1;
		scanf("%s",str);
		length = strlen(str);
		
		for(center=0;center<length;center++){
			count = 0;
			for(j=center-1,k=center+1 ; j>=0 && k<length ;j--,k++){
				if(str[j] == str[k]){
					count = count + 2;
				}
				else break;
				if(count+1>max){
					max = count +1;
				}
			}
			count=0;
			for(j=center,k=center+1 ; j>=0 && k<length ; j--,k++){
				if(str[j] == str[k]){
					count = count + 2;
				}
				else break;
				if(count>max){
					max = count;
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
