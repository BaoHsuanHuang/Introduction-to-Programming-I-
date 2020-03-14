#include <stdio.h>

char map[1001][1001];
int m,n;
int count=0,max=0;

void check(int i,int j);

int main(void)
{
	int i,j;
	
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		while (getchar() != '\n');
		for(j=0;j<n;j++){
			scanf("%c",&map[i][j]);
			if(map[i][j] == '#') map[i][j] = 1; 
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(map[i][j] == 1){
				count = 0;
				check(i,j);
				if(count>max){
					max = count;
				}
			}
		}
	}
	
	printf("%d\n",max);
	return 0;
}

void check(int i,int j)
{
	if(i>=0 && i<m && j>=0 && j<n){
		if(map[i][j] == 1){
			count++;
			map[i][j] = 0;
			check(i-1,j);
			check(i,j-1);
			check(i+1,j);
			check(i,j+1);
		}
	}
}

