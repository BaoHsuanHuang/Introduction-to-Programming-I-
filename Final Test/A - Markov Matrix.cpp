#include <stdio.h>
int main(void)
{
	int T;
	int n;	//city
	int i,j,k;
	float a[5][5];
	int x[5][2];
	int p;
	int ans;
	int flag = 1;
	
	scanf("%d",&T);
	while(T--){
		flag = 1;
		scanf("%d",&n);
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%f",&a[i][j]);
			}
		}
		for(i=0;i<n;i++){
			scanf("%d",&x[i][0]);		//population : x[0][0]
		}								//			   x[1][0]		
		scanf("%d",&p);
		
		for(ans=0;x[0][0]>p;ans++){
			for(i=0;i<n;i++){
				x[i][1] = x[i][0];
				x[i][0] = 0;
			}
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					x[i][0] += a[i][j]*x[j][1];
				}
			}
			if(x[0][0] == x[0][1]){		//達到馬可夫矩陣 
				flag = 0;
				break;
			}
		}
		
		if(flag==1) printf("%d\n",ans);
		else printf("Never\n");
	}
	return 0;
}


/*
#include <stdio.h>

int main(void)
{
	int t,n;
	float a[6][6];
	float x[6],compute[6];
	int p;
	int i,j,k;
	
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				scanf("%f",&a[j][k]);
			}
		}
		
		for(j=0;j<n;j++){
			scanf("%f",&x[j]);
		}
		scanf("%d",&p);
		
		int ans=0;
		if(x[0] > p){
			
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					compute[j] += a[j][k] * x[k];
					printf("%f\n",compute[j]);
				}		
			}
			
			for(j=0;j<n;j++){
				x[j] = compute[j];
			}
			printf("%f\n",x[0]);
			ans++;
		}

		printf("%d\n",ans);
	
	}
	return 0;
}
*/
