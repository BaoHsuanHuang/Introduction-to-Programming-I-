#include <stdio.h>
int main(void)
{
	int input[10];
	int i;
	int ans=0;
	//int a;
	int flag[10]={0};
	
	for(i=1;i<=9;i++){
		scanf("%d",&input[i]);
	}
	
	ans = input[1];
	flag[1] = 1;
	i = input[1];
	
	while(flag[input[i]] != 1){
		ans += input[i];
		flag[i] = 1;
		i = input[i];
	}
	ans += input[i];
	printf("%d\n",ans);
	
	return 0;
}
