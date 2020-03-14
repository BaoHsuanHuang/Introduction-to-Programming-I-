#include <stdio.h>
int main(void)
{
	int T,n;
	int i,j,v[10000],k,m,c;
	
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&v[j]);
		}
		for(j=0;j<n-1;j++){
			for(k=j+1;k<n;k++){
				if(v[j]>v[k]){
					c = v[j];
					v[j] = v[k];
					v[k] = c;
				}
			}
		}
		for(m=0;m<n-1;m++){
			printf("%d ",v[m]);
			
		}
		printf("%d\n",v[n-1]);
		
	}
	return 0;
}




/*
數字比大小 
#include<stdio.h>
int main(void)
{
	int str[5] = {11,2,10,3,5};
	int i,c,j,k;
	
	for(i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if(str[i]>str[j]){
				c = str[i];
				str[i] = str[j];
				str[j] = c;
			}
		}
	}
	for(k=0;k<5;k++){
		printf("%d ",str[k]);
	}
	return 0;
 }
 */ 
