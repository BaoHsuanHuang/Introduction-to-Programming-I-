//D - Determinant
#include <stdio.h>

int n;
int matrix[10][10];
long long int determinant(int m[10][10],int n);			//point

int main(void)
{
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
	long long int ans=0;
	long long int ans_1=0;
	int i;
	int tmp[10][10];
	int row,col;
	
	if(n==2){			// <= or == 
		ans = m[0][0]*m[1][1] - m[0][1]*m[1][0];
		return ans;			//point
	}else{			//point
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
				ans_1 = m[0][i]*determinant(tmp,n-1);
			}else{
				ans_1 = (-1)*m[0][i]*determinant(tmp,n-1);
			}
			ans = ans + ans_1;
		}
		return ans;
	}
	//return ans;
}
