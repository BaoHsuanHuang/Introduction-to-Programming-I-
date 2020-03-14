//遞迴 
#include <stdio.h>

int matrix[10][10];
long long int determinant(int n,int m[10][10]); 

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
	ans = determinant(n,matrix);
	
	printf("%lld\n",ans);
	return 0;
}

long long int determinant(int n,int m[10][10])
{
	long long int ans=0,ans_1=0;
	int i;
	int tmp[10][10];
	int row,col;
	
	if(n<=2){
		ans = m[0][0]*m[1][1] - m[0][1]*m[1][0];
		return ans;
	}
	else{
		for(i=0;i<n;i++){
			for(row=0;row<n-1;row++){		//n-1的條件是設給tmp的 
				for(col=0;col<i;col++){
					tmp[row][col] = m[row+1][col];				
				}
			}
			
			for(row=0;row<n-1;row++){
				for(col=i;col<n-1;col++){
				tmp[row][col] = m[row+1][col+1]; 
				}
			}
			
			if(i%2==0){
			ans_1 = m[0][i]*determinant(n-1,tmp);
			}
			else if(i%2==1){
			ans_1 = (-1)*m[0][i]*determinant(n-1,tmp);
			}
			ans = ans + ans_1;
		}
		return ans;
}
}



/*#include <stdio.h>

int main(void)
{
	int n;
	long long int matrix[100][100];
	int i,j,k;
	long long int A=0,B=0,ans=0,a=1,b=1;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		a = 1;
		for(k=0;k<n;k++){
			a *= matrix[(0+k)%n][(i+k)%n];
		}
		A += a;
	}
	//printf("A : %lld\n",A);
	
	for(i=n-1;i>=0;i--){
		b = 1;
		for(k=0;k<n;k++){
			b *= matrix[(0+k)%n][(k+n-i)%n];
			printf("b : %lld\n",b);
		}
		B += b;
		printf("B : %lld\n",B);
	}
	
	
	ans = A-B;
	
	printf("%lld\n",ans);
	
	return 0;
}
*/
