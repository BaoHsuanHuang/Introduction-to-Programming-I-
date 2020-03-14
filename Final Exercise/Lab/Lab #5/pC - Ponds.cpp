#include <stdio.h>

void check(int i,int j);

int m,n;
char map[1000][1000];

int main(void)
{
	
	int i,j;
	
	int count=0;
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf(" %c",&map[i][j]);
			if(map[i][j]=='~') map[i][j]=1;
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(map[i][j]==1){
				check(i,j);
				count++;
			}
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}

void check(int i,int j)
{
	if(i>=0 && i<m && j>=0 && j<n){
		if(map[i][j]==1){
			
			map[i][j] = 0;
			
			check(i-1,j);
			check(i+1,j);
			check(i,j-1);
			check(i,j+1);
		}
	}

}
