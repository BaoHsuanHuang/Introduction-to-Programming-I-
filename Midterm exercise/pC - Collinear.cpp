/*
#include <stdio.h>
int main(void)
{
	int T,N,x[100]={0},y[100]={0},point[101]={0};
	int i,j,k,m,count=2,ans=0,n,flag=0;
	float m1,m2,dx,dy;
	
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		scanf("%d",&N);
		count=2;
		for(j=0;j<N;j++){
			scanf("%d%d",&x[j],&y[j]);    
			//scanf("%d",&y[j]);   
		}
		
		for(j=0;j<N;j++){
			for(k=j+1;k<N;k++){
				dx = x[k]-x[j];
				dy = y[k]-y[j];
				m1 = dy/dx;
				
				
				if(dx==0) flag=1;
				for(m=0;m<N;m++){
					if(m==j || m==k) continue;
					else{
						dx = x[m]-x[j];
						dy = y[m]-y[j];
						if(flag==1) {
							if(dx==0 && x[m]==x[j]) count++;
						}else{
							m2 = dy/dx;
							if( m2 == m1 ) count++;
						}						
					}					
				}
				point[count]++;
				count = 2;
				flag=0;
			}
		}
		for(n=3,ans=0;n<101;n++){
			ans += point[n]*2/n/(n-1);
			point[n]=0;
		}
		printf("%d\n",ans);
		//printf("\n");
	}
	return 0;
 }
*/
/*
#include <stdio.h>
int main(void)
{
	int T,N,x[101]={0},y[101]={0},point[101]={0};
	int i,j,k,m,count=2,ans=0,n,flag=0;
	float m1,m2,dx,dy;
	
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		scanf("%d",&N);
		for(j=1;j<=N;j++){
			scanf("%d",&x[j]);   // x[1] = x1 
			scanf("%d",&y[j]);   // y[1] = y1
		}
		count=2;
		for(j=1;j<=N;j++){
			for(k=j+1;k+j<=N;k++){
				dx = x[k]-x[j];
				dy = y[k]-y[j];
				m1 = dy/dx;
				
				
				if(dx==0) flag=1;
				for(m=1;m<=N;m++){
					if(m==j || m==k) continue;
					else{
						dx = x[m]-x[j];
						dy = y[m]-y[j];
						if(flag==1) {
							if(dx==0 && x[m]==x[j]) count++;
						}else{
							m2 = dy/dx;
							if( m2 == m1 ) count++;
						}						
					}					
				}
				point[count]++;
				count = 2;
				flag=0;
			}
		}
		for(n=3,ans=0;n<101;n++){
			ans += point[n]*2/n/(n-1);
			point[n]=0;
		}
		printf("%d\n",ans);
		printf("\n");
	}
	return 0;
 }
*/ 

#include <stdio.h>
int main() {
    int T, N;
    int i, j, k, a, b, c, count, ans, point[101]={0}, flag = 0;
    float m1, m2, x[100]={0}, y[100]={0}, dx, dy;
    scanf("%d", &T);
    for(i=0; i<T; i++){
        scanf("%d", &N);
        count = 2;
        for (j=0; j<N; j++) {
            scanf("%f%f", &x[j], &y[j]);
        }
        for (a=0; a<N; a++){
            for (b=a+1; b<N; b++) {
                dx = x[a] - x[b];
                dy = y[a] - y[b];
                m1 = dy / dx;
                if (dx == 0) flag = 1;
                for(c=0; c<N; c++){
                    if(c == a || c == b) continue;
                    else {
                        dx = x[c] - x[a];
                        dy = y[c] - y[a];
                        if (flag == 1){
                            if (dx == 0 && x[c] == x[a]) count++;
                        } else{
                            m2 = dy / dx;
                            if (m1 == m2) {count++;}
                        }
                    }
                }
                point[count] ++;
                count = 2;
                flag = 0;
            }
            
        }
        for (k=3, ans=0; k<101; k++) {
            ans += point[k] * 2 / k / (k - 1) ;
            point[k] = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
