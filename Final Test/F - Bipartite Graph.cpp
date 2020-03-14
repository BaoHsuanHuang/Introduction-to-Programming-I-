#include <stdio.h>

int neighbor[1001][1001];
int color[1001];
int isBipartite;

void DFS(int vertex,int pre_color);

int main(void)
{
	int T;
	int v,e;
	int v1,v2;
	int i,j;
	
	scanf("%d",&T);
	while(T--){
		for(i=0;i<1001;i++){
			for(j=0;j<1001;j++){
				neighbor[i][j] = 0;
			}
		}
		for(i=0;i<1001;i++){
			color[i] = 0;
		}
		scanf("%d%d",&v,&e);
		for(i=0;i<e;i++){
			scanf("%d%d",&v1,&v2);
			
			neighbor[v1][v2] = 1;
			neighbor[v2][v1] = 1;
		}
		
		isBipartite = 1;
		
		DFS(1,-1);
		
		if(isBipartite==1) printf("Yes\n");
		else printf("No\n");
		
	}
	return 0;
}

void DFS(int vertex,int pre_color)
{
	int i;
	
	color[vertex] = (-1)*pre_color;
	for(i=1;i<=1000;i++){
		if(i!=vertex && neighbor[i][vertex]==1){
			if(color[i]==color[vertex]){
				isBipartite = 0;
				break;
			}
			else if(color[i]==0){
				DFS(i,color[vertex]);
			}
		}
	}
	
}




