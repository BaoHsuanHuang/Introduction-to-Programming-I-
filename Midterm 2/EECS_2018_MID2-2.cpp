void max_pooling(int A[500][500], int *m, int *n)
{	
	int i,j;
	for(i=0;i<*m;i+=2){
		for(j=0;j<*n;j+=2){
			if(A[i+1][j] > A[i][j]) A[i][j] = A[i+1][j];
			if(A[i][j+1] > A[i][j]) A[i][j] = A[i][j+1];
			if(A[i+1][j+1] > A[i][j]) A[i][j] = A[i+1][j+1];
			A[i/2][j/2] = A[i][j];
		}
	}
	*m = *m/2;
	*n = *n/2;
	
	//* m /= 2;
	//*n /=2;	
}


