#include <stdio.h>

void check(int i,int j);
int m,n;
char map[1001][1001];

int main(void)
{
	int i,j;
	char c;
	int ans=0;
	
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		while(getchar() != '\n');	// 因為 char 陣列結尾是 \n 
		for(j=0;j<n;j++){
			scanf("%c",&c);
			if(c == '~') map[i][j] = 1;
		}
	}
	
	for(i=0 ; i<m ; i++){
		for(j=0 ; j<n ; j++){
			if(map[i][j] == 1){
				check(i,j);
				ans++;
			}
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}

void check(int i,int j)
{
	if(i>=0 && i<m && j>=0 && j<n){
		if(map[i][j] == 1){
			map[i][j] = 0;
			check(i-1,j);
			check(i,j-1);
			check(i+1,j);
			check(i,j+1);
		}
	}
	
}
