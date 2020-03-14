#include <stdio.h>

void check(int i,int j);
char map[1001][1001];
int m,n;
int flag=0;

int main(void)
{
	int i,j;
	int x,y;
	
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		while(getchar() != '\n');
		for(j=0;j<n;j++){
			scanf("%c",&map[i][j]);
			if(map[i][j] == 'e'){
				x = i;
				y = j;
			}
		}
	}
	check(x,y);
	
	if(flag==1) printf("Alive!\n");
	else printf("Dead!\n"); 
	
	return 0;
}

void check(int i,int j)
{
	if(i>=0 && i<m && j>=0 && j<n && map[i][j] !='^' && flag==0){		// point
		if(map[i][j]=='~'){
			flag = 1;
		}
		else{
			map[i][j] = '^';	// point
			check(i-1,j);
			check(i,j-1);
			check(i+1,j);
			check(i,j+1);
		}
	}
}

