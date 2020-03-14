#include <stdio.h>

int count = 0;
int credit[20]={0};
int number[20]={0};
int sum=0;
void check(int sum,int cur,int n);

int main(void)
{
	int n;
	int i;
	char course[101];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(" %s",course);
		scanf("%d",&credit[i]);
		sum += credit[i];
	}
	check(sum,0,n);
	
	printf("%d\n",count); 
	return 0;
}

void check(int sum,int cur,int n)
{
	if(cur<n){
		check(sum,cur+1,n);
		if(number[cur]==0 && sum-credit[cur]>=16){
			number[cur] = 1;
			count++;
			check(sum-credit[cur],cur+1,n);
			number[cur] = 0;
		}	
	}
}
