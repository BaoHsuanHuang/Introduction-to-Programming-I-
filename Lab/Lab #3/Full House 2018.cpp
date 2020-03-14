#include <stdio.h>
#include <string.h>

int main(void)
{
	char input[5][3];
	int cards[14],T;
	int flag2,flag3;
	int i,j;
	
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		scanf("%s%s%s%s%s",input[0],input[1],input[2],input[3],input[4]);
		for(j=1;j<=13;j++){
			cards[j]= 0;
		}
		flag2 = flag3 = 0;
		for(j=0;j<5;j++){
			if(input[j][0] == 'A') cards[1]++;
			else if(input[j][0] == '1') cards[10]++;
			else if(input[j][0] == 'J') cards[11]++;
			else if(input[j][0] == 'Q') cards[12]++;
			else if(input[j][0] == 'K') cards[13]++;
			else cards[input[j][0]-'0']++;
		}
		for(j=1;j<=13;j++){
			if(cards[j] == 2) flag2 = 1;
			if(cards[j] == 3) flag3 = 1;
		}
		if(flag2==1 && flag3==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
