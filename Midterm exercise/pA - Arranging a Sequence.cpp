#include <stdio.h>
#include <string.h>

int main(void)
{
	int n,m,i;
	int input[200001]={0};
	int flag[200001] = {0};
	
	scanf("%d %d",&n,&m);
	
	for(i=m;i>=1;i--)
	{
		scanf("%d",&input[i]);
		flag[input[i]] = 1;
	}
	for(i=1;i<=n;i++){   // QUESTION 
		if(flag[input[i]] == 1){
			printf("%d\n",input[i]);
			flag[input[i]] = -1;
		}
	}
	for(i=1;i<=n;i++){
		if(flag[i] == 0){
		printf("%d\n",i);
		}
	}

	return 0;
}






























/* #include <stdio.h>
int main(void)
{
	int n,m;
	int i,j,str[200000],e[100000],a,b,k=1,x=0;
	
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++){
		str[i] = i+1;
	}
	for(j=0;j<m;j++){
		scanf("%d",&e[j]);
	}
	for(j=0;j<m;j++){
		if(e[j]>x){
			a = e[j];
			b = str[a-1];
			for(i=a-1;i>0;i--){
				str[i] = str[i-1];
			}
			str[0] = b;
		}
		else{
			a = e[j];
			b = str[a-1+k];
			for(i=a-1+k;i>0;i--){
				str[i] = str[i-1];
			}
			str[0] = b;
			k=k+1;
		}
		x = e[j];
	}
	for(i=0;i<n;i++){
		printf("%d\n",str[i]);
	}
	
	return 0;
}

#include <stdio.h>

int main(void)
{
	int n,m,original[200000],input[100000],output[200000];
	int i,j,k=1,is=0,a;
	
	scanf("%d%d",&n,&m);
	
	for(i=1;i<=n;i++){
		original[i] = i;
	}
	for(j=1;j<=m;j++){
		scanf("%d",&input[j]);
	}
	
	for(j=1;j<=m;j++){
		for(i=1;i<=n;i++){
			if(input[j]==original[i]){
				original[i] = original[i+1];
			}
		}
	}

	for(j=m;j>=1;j--){
		printf("%d\n",input[j]);
	}
	
	for(i=1;i<=n-m;i++){
		printf("%d\n",original[i]);
	}
	for(a=1;a<=n-m;a++){
		printf("%d\n",output[a]);
	}
	
	return 0;
}


4 -> input[1]
2 -> input[2]
5 -> input[3]

original[5] = 1,2,3,4,5
for(i=1;i<=n;i++){
		is = 0;
		for(j=1;j<=m;j++){
			if(original[i]==input[j])
			original[k-1] = original[k];
		}
		if(is == 0){
			output[k] = original[i];
			k++;
		}
	}
*/
