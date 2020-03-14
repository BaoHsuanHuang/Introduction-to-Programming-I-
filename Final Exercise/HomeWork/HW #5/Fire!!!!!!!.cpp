#include <stdio.h>

int m,n;
char map[1000][1000];
int flag = 0;

void check(int i,int j);

int main(void)
{
	int i,j;
	int x,y;
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf(" %c",&map[i][j]);
			if(map[i][j]=='e'){
				x = i;
				y = j;
			}
			//else if(map[i][j]=='~') map[i][j] = 1;
		}
	}
	
	check(x,y);
	
	if(flag==1) printf("Alive!\n");
	else printf("Dead!\n");
	
	return 0;
}

void check(int i,int j)
{
	if(i>=0 && i<m && j>=0 && j<n && map[i][j]!='^' && flag == 0){
		if(map[i][j]=='~'){
			flag = 1;
		}
		else{
			map[i][j] = '^';
			check(i-1,j);
			check(i+1,j);
			check(i,j-1);
			check(i,j+1);
		}
	}
}
