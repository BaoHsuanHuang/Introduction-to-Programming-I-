#include <stdio.h>

int main(void)
{
	int T;
	int n;
	int i,j;
	float matrix[5][5];
	int x[5][2];
	int p;
	int ans;
	int flag=1;
	scanf("%d",&T);
	
	while(T--){
		scanf("%d",&n);
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%f",&matrix[i][j]);
			}
		}
		for(i=0;i<n;i++){
			scanf("%d",&x[i][0]);
		}
		scanf("%d",&p);
		flag = 1;
		for(ans=0;x[0][0]>p;ans++){
			for(i=0;i<n;i++){
				x[i][1] = x[i][0];
				x[i][0] = 0;
			}
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					x[i][0] += matrix[i][j]*x[j][1];
				}		
			}
			if(x[0][0]==x[0][1]){
				flag = 0;
				break;
			}
		}
		if(flag==1) printf("%d\n",ans);
		else printf("Never\n");
	}
	return 0;
} 
