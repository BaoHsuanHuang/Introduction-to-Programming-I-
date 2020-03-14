//XOR運算：
//0 XOR 0         0
//0 XOR 1         1
//1 XOR 0         1
//1 XOR 1         0

#include <stdio.h>

int binary[100000][25] = {0};		//point : 要設在global才可以開那麼大 

int main(void)
{	
	int N;
	long long int sum=0, two = 1;
	int i,j;
	int input;
	
	int one=0,zero=0;
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		scanf("%d",&input);
		
		for(j=0;input>0;j++){		//point : 條件假設 
			binary[i][j] = input%2;
			input /= 2;
		}
	}
	
	for(i=0;i<25;i++){
		zero = 0;
		one = 0;
		for(j=0;j<N;j++){
			if(binary[j][i]==1) one++;
			else zero++;
		}
		if(one>zero) sum = sum + zero*two;
		else sum = sum + one*two;
		two *= 2;
	}
	printf("%lld\n",sum);
	return 0;
} 
