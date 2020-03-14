#include<stdio.h>
void find_seq(int);
int N;
int A[1000];

int main(void)
{
	int i;
	
	scanf("%d",&N);
	
	for(i=1;i<=N;i++){
		scanf("%d",&A[i]);
	}
	
	find_seq(1);
	
	return 0;
}

void find_seq(int k)
{
	if(k < N){
		find_seq(2*k);
		printf("%d ",A[k]);
		find_seq(2*k+1);
	}
	if (k==N){
		printf("%d\n",A[k]);
	}
}







/*

#include<stdio.h>
int array[1500];
int n;
void a(int k);
int main (void)
{
    int i;
    scanf("%d", &n);
    for(i=1 ; i<=n ;i++)
    {
        scanf("%d",&array[i]);
    }
    a(1);
    return 0;
}
void a(int k)
{
    if(k<n)
    {
        a(2*k);
        printf("%d ",array[k]);
        a(2*k+1);
    }
    if(k==n)
    {
        printf("%d\n", array[k]);
    }
}


*/
