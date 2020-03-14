/*
// (Lab 3) Full House 2018 
#include <stdio.h>
int main(void)
{
	int t;
	int i,j;
	char input[5][3]={0};
	
	scanf("%d",&t);
	for(i=0;i<t;i++){
		for(j=0;j<5;j++){
			scanf("%s",input[j]);
		}
		
		int flag[15]={0};
		
		for(j=0;j<5;j++){
			if(input[j][0]=='A') flag[1]++;
			else if(input[j][0]=='1') flag[10]++;
			else if(input[j][0]=='J') flag[11]++;
			else if(input[j][0]=='Q') flag[12]++;
			else if(input[j][0]=='K') flag[13]++;
			else flag[input[j][0]-'0']++;		// point : -'0'
		}
		//for(j=1;j<=13;j++){
		//	printf("%d ",flag[j]);
		//} 
		int k,flag2=0,flag3=0;
		for(k=1;k<=13;k++){
			if(flag[k]==2) flag2=1;
			if(flag[k]==3) flag3=1;
		}
		if(flag2==1 && flag3==1){
			printf("YES\n");
		}else printf("NO\n");
	}
	return 0;
}
*/

/*
// (Midterm1_Practice) Simple integer sorting
#include <stdio.h>
int main(void)
{
	int T,n,input[15000]={0};
	int i,j,k;
	
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d",&n);
		
		for(j=0;j<n;j++){
			scanf("%d",&input[j]);
		}
		
		for(j=0;j<n;j++){
			for(k=j+1;k<n;k++){
				if(input[k]<input[j]){
					int c;
					c = input[j];
					input[j] = input[k];
					input[k] = c;
				}
			}
		}
			
		for(j=0;j<n-1;j++){
			printf("%d ",input[j]);
		}
		printf("%d\n",input[n-1]);
	}
	return 0;
} 
*/

/*
// (Midterm1_Practice) pD - Distrait 
#include <stdio.h>
int main(void)
{
	int pos[50][2],input;
	int i,j;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			scanf("%d",&input);
			pos[input][0] = i;
			pos[input][1] = j;
		}
	}
	
	int T,n,x;
	int a,b,c;
	
	
	scanf("%d",&T);
	for(a=0;a<T;a++){
		scanf("%d",&n);
		
		int row[50]={0},col[50]={0},left=0,right=0;
		int flag = 0;		// point
		
		for(b=0;b<n;b++){
			scanf("%d",&x);
			
			row[pos[x][0]]++;
			col[pos[x][1]]++;
			
			if(pos[x][0]==pos[x][1]) right++;
			if(pos[x][0]+pos[x][1]==4) left++;
			
			if(row[0]==5 || row[1]==5 || row[2]==5 || row[3]==5 || row[4]==5 ||
			col[0]==5 || col[1]==5 || col[2]==5 || col[3]==5 || col[4]==5 || 
			right==5 || left==5) {
				printf("Case #%d: %d\n",a+1,b+1);
				flag = 1;
				break;
			}
		}
		for(b=b+1;b<n;b++){
			scanf("%d",&x);
		}
		if(flag==0) printf("Case #%d: Not yet \\(^o^)/\n",a+1);
	}
	return 0;
}
*/
/*
// (Midterm1_Practice) pC - Collinear
#include <stdio.h>
int main(void)
{
	int T,n;
	int i,j,a,b,c;
	float dx,dy,m1,m2,x[100]={0},y[100]={0};
	
	scanf("%d",&T);
	for(i=0;i<T;i++){
		
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%f%f",&x[j],&y[j]);
		}	
		
		int flag=0;
		int count=2;
		int point[100]={0};
		for(a=0;a<n;a++){
			for(b=a+1;b<n;b++){
				dx = x[b] - x[a];
				dy = y[b] - y[a];
				m1 = dy/dx;
				if(dx == 0) flag=1;
				
				for(c=0;c<n;c++){
					if(c==a || c==b) continue;
					else{
						dx = x[c] - x[a];
						dy = y[c] - y[a];
						
						//if(flag==1 && x[c]==x[a]) count++;
						if(flag==1){
							if(x[c]==x[a]) count++;
						}
						else{
							m2 = dy/dx;
							if(m2 == m1) count++;
						}
					}
				}
				point[count]++;
				count=2;
				flag=0;
			}
		}
		int k;
		int ans=0;
		for(k=3;k<100;k++){
			//if(point[k]>=3){
				ans = ans + point[k]*2/k/(k-1);
				point[k]=0;
			//}
		}
		printf("%d\n",ans);
	}
	return 0;
}
*/

// Longest Palindrome substring
#include <stdio.h>
#include <string.h>
int main(void)
{
	int N;
	int i,c,length,j,k;
	char str[10000];
	
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s",str);
		length = strlen(str);
		
		int count = 0;
		int max = 1;
		
		for(c=0;c<length;c++){
			count = 0;
			for(j=c-1,k=c+1; j>=0 && k<length ; j--,k++){
				if(str[j]==str[k]) count = count+2;
				else break;
				
				if(count+1>max){
					max = count+1;
				}
			}
			count=0;
			for(j=c,k=c+1 ; j>=0 && k<length ; j--,k++){
				if(str[j]==str[k]) count = count+2;
				else break;
				
				if(count>max){
					max = count;
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}



