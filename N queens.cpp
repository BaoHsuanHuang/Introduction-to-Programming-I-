#include <stdio.h>
int n;
int q[50];
int count = 0;
void place(int row);
int valid(int r,int c);

int main(void)
{
	
	scanf("%d",&n);
	
	place(0);
	
	printf("%d\n",count);
	
	return 0;
}

int valid(int r,int c)
{
	int i;
	for(i=0;i<r;i++){
		if(q[i]==c || q[i]-c==i-r || c-q[i]==i-r){
			return 0;
		}
	}
	return 1;	
}

void place(int row)
{
	int j;
	if(row==n){
		count++;
	}else{
		for(j=0;j<n;j++){
			if(valid(row,j)){
				q[row] = j;
				place(row+1);
			}
		}	
	}
}
