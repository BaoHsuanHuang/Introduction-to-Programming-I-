#include <stdio.h>
#include <string.h>

int main(void)
{
	int T;
	char input[5][3];
	int card[14]={0};
	int i;
	int flag_2=0,flag_3=0;
	scanf("%d",&T);
	
	while(T--){
		scanf("%s%s%s%s%s",input[0],input[1],input[2],input[3],input[4]);		//point
		
		for(i=1;i<=13;i++){
			card[i] = 0;
		}
		
		for(i=0;i<5;i++){
			if(input[i][0]=='A') card[1]++;
			else if(input[i][0]=='J') card[11]++;
			else if(input[i][0]=='Q') card[12]++;
			else if(input[i][0]=='K') card[13]++;
			else if(input[i][0]=='1') card[10]++;		//point
			else card[input[i][0]-'0']++;		//point 
		}
		
		flag_2 = flag_3 = 0;
		
		for(i=1;i<=13;i++){
			if(card[i]==2) flag_2 = 1;
			if(card[i]==3) flag_3 = 1;
		}
		
		if(flag_2==1 && flag_3==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
