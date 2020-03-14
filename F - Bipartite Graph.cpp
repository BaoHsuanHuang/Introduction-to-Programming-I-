#include <stdio.h>

int neighbor[1000][1000];
int color[1000];
int isBipartite;
int v,e;

void DFS(int vertex,int pre_color);

int main(void)
{
	int T;
	
	int v1,v2;
	int i,j;
	
	scanf("%d",&T);
	
	while(T--){
		for(i=0;i<1000;i++){
			for(j=0;j<1000;j++){
				neighbor[i][j] = 0;
			}
		}
		
		for(i=0;i<1000;i++){
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
	color[vertex] = pre_color * (-1);
	
	for(i=0;i<1000;i++){		//point
		if(i!=vertex && neighbor[i][vertex]==1){
			if(color[i]==color[vertex]){
				isBipartite = 0;
				break;
			}
			else if(color[i]==0){		//point
				DFS(i,color[vertex]);
			}
		}
	}
	
}





