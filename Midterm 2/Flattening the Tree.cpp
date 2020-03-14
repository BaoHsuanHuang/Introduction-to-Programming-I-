/*// Flattening the Tree  
#include <stdio.h>

int n;
int a[1500];
void find_seq(int);

int main(void)
{
	int i;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	find_seq(1);
	
	return 0;
}

void find_seq(int k)
{
	if(k<n){
		find_seq(2*k);
		printf("%d ",a[k]);
		find_seq(2*k + 1);
	}
	if(k==n){
		printf("%d\n",a[k]);
	}
}
*/










// Flattening the Tree  (2)
#include <stdio.h>

int n;
int a[1500];
void find_seq(int);

int main(void)
{
	int i;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	find_seq(1);
	
	return 0;
}

void find_seq(int k)
{
	if(k<n){
		
		printf("%d ",a[k]);
		find_seq(2*k);
		find_seq(2*k + 1);
	}
	if(k==n){
		printf("%d\n",a[k]);
	}
}

