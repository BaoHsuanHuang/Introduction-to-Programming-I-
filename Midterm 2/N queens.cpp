// N �ӬӦZ 
#include<stdio.h>

int q[20]={0};
int N;
int count=0;
void place(int r);
int valid(int ,int );

int main(void)
{
	scanf("%d",&N);
	
	place(0);
	printf("%d",count);
	
	return 0;
}

int valid(int r,int c)
{
	int i;
	for(i=0;i<=r-1;i++){
		if(q[i]==c || r-i==q[i]-c || r-i==c-q[i]){
			return 0;
		}
	}
	return 1;
}

void place(int r)
{
	int j;
	if(r>=N){
		count++;
	}else{
		for(j=0;j<N;j++){
			if(valid(r,j)){
				q[r] = j;
				place(r+1);
			}
		}
	}
	
}
