#include <stdio.h>

int matrix[10][10];
long long int determinant(int m[10][10],int n);

int main(void)
{
	int n;
	int i,j;
	long long int ans;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	
	ans = determinant(matrix,n);
	
	printf("%lld\n",ans);
	
	return 0;
}

long long int determinant(int m[10][10],int n)
{
	int row,col;
	int i;
	long long int ans1=0;
	long long int ans=0;
	int tmp[10][10];		//point
	if(n==2){
		ans = m[0][0]*m[1][1] - m[0][1]*m[1][0];
		return ans;
	}else{
		for(i=0;i<n;i++){
			for(row=1;row<n;row++){
				for(col=0;col<i;col++){
					tmp[row-1][col] = m[row][col];
				}
			}
			for(row=1;row<n;row++){
				for(col=i+1;col<n;col++){
					tmp[row-1][col-1] = m[row][col];
				}
			}
			if(i%2==0){
				ans1 = m[0][i]*determinant(tmp,n-1);
			}else if(i%2==1){
				ans1 = (-1)*m[0][i]*determinant(tmp,n-1);
			}
			ans = ans+ans1;
		}
		return ans;	
	}	
}

