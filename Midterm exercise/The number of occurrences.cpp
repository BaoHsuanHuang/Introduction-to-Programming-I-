/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char str_A[4],str_B[10];
	int n,i,a,b,j,ans,k,m,c,strlen;
	
	scanf("%s",str_A);
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		ans = 0;
		c = 0;
		scanf("%s",str_B);
		a = strlen(str_A);
		b = strlen(str_B);
		for(j=0;j<=b-a;j++){
			k=j;
			m=0;
			strlen=0;
			while(str_B[k]==str_A[m] && strlen<a){
				k++;
				m++;
				strlen++;
			} 
			if(strlen==a){
				ans=ans+1;
			}
		}
		printf("%d",ans);
		
	}
	return 0;
}
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str_A[5],str_B[10];
	int N,i,ans=0,a,b,j,k;
	
	scanf("%s",str_A);
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		scanf("%s",str_B);
		a = strlen(str_A);
		b = strlen(str_B);
		int time=0;
		for(j=0;j<=b-a;j++){
			int correct = 0;
			for(k=0;k<a;k++){
				if(str_A[k]==str_B[k+j]) correct++;
			}
			if(correct==a) time++;
		}
		if(time>ans) ans=time;
	}
	printf("%d",ans);
	
	return 0; 
}
