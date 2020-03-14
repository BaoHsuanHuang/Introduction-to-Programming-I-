#include <stdio.h>

int binary[100000][25];

int main(void)
{
	int n;
	int i,j;
	int input;
	int one=0,zero=0;
	long long int two=1;
	long long int ans=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){

		scanf("%d",&input);
		for(j=0;input>0;j++){
			binary[i][j] = input%2;
			input = input/2;
		}
	}
	
	for(i=0;i<25;i++){
		one = 0;
		zero = 0;
		for(j=0;j<n;j++){
			if(binary[j][i]==1) one++;
			else zero++;	
		}
		if(one>zero) ans += zero*two;
		else ans += one*two;
		
		two *= 2;
	}
	
	printf("%lld\n",ans);
	
	return 0;
} 
