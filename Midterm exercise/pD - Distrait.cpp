#include <stdio.h>
int main(void)
{
	int pos[26][2],x,rs[5] = {0},cs[5] = {0},ul=0,ur=0,flag = 0;
	int T,N,i,j,k;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			scanf("%d",&x);
			pos[x][0] = i;
			pos[x][1] = j;
		}
	}
	scanf("%d",&T);
	for(k=1;k<=T;k++){
		scanf("%d",&N);
		
		for(i=0;i<5;i++){
			rs[i] = 0;
			cs[i] = 0;
			ul = 0;
            ur = 0;
            flag = 0;
		}
		
		for(i=1; i<=N; i++){
            scanf("%d", &x);
            rs[pos[x][0]] ++;
            cs[pos[x][1]] ++;
            
            if (pos[x][0] == pos [x][1]) ul ++;
            if ((pos[x][0]+pos[x][1]) == 4) ur ++;
            
            if (rs[0] == 5 || rs[1] == 5 || rs[2] == 5 || rs[3] == 5 || rs[4] == 5 
			|| cs[0] == 5 || cs[1] == 5 || cs[2] == 5 || cs[3] == 5 
			|| cs[4] == 5 || ul == 5 || ur == 5) {
                printf("Case #%d: %d\n", k , i);
                flag = 1;
                break;
            }
		}
		
		for(i=i+1; i<=N; i++){
            scanf("%d", &x);
        }
        if (flag == 0) printf("Case #%d: Not yet \\(^o^)/\n", k);
	}
	
	return 0;
} 








/*#include <stdio.h>
int main(void)
{
	int A[10][10],number[100],ans[100];
	int i,j,a,b,c,k=0,m;
	int T,N,answer=0,times;
	
	for(i=1;i<6;i++){
		for(j=1;j<6;j++){
			scanf("%d",&A[i][j]);
		}
	}
	
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		scanf("%d",&N);
		
		for(j=1;j<=N;j++){
			scanf("%d",&number[j]);
		}
		if(N<5) printf("Case #%d: Not yet \\(^o^)/\n",i+1);
		else{
			k=0;
			for(c=1;c<=N;c++){
				for(a=1;a<6;a++){
					for(b=1;b<6;b++){
						if(number[c] == A[a][b]){
							ans[k] = a;
							k++;
						}
					}
				}
			}
			for(k=0;k<N;k++){
				answer=0;
				for(m=1;m<N-k;m++){
					if(ans[k+m] == ans[k]) answer++;
				}
				if(answer == 4){
					printf("Case #%d: %d\n",i+1,k+m-1+1);
				}
			}else printf("Case #%d: Not yet \\(^o^)/\n",i+1);
		}
		
	}
	return 0;
} 
*/



