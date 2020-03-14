#include <stdio.h>

void water(int i,int j);
char map[1000][1000];
int m,n;

int main(void)
{
	int ans=0;
	int i,j;
	char c;
	
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		while (getchar()!='\n');		// point
		for(j=0;j<n;j++){
			scanf("%c",&c);
			if( c == '~') map[i][j]=1;
		}
	}

	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(map[i][j]==1){
				water(i,j);
				ans++;	
			}
		}
	}

	printf("%d\n",ans);
	
	return 0;
}

void water(int i,int j)
{
	if(i>=0 && j>=0 && i<m && j<n){
		if(map[i][j]==1){
			map[i][j] = 0;
			water(i-1,j);
			water(i,j+1);
			water(i+1,j);
			water(i,j-1);
		}
	}
}
