// premute
#include <stdio.h>

void premute(char a[],int n);
void change(char * x, char  * y);

int main(void)
{
	char a[] = "abcd";
	
	premute(a,4);
	
	return 0;
}

void premute(char a[],int n)
{
	int i;
	if(n == 1) printf("%s\n",a);
	else{
		for(i=n-1;i>=0;i--){
			change(&a[i],&a[n-1]);
			premute(a,n-1);
			change(&a[i],&a[n-1]);
		}

	}
}

void change(char * x,char * y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}





/*
// 指標 + 遞迴
#include <stdio.h>
//#include <string.h> 
//int a[10];
int search(int * ap,int left,int right,int key);

int main(void)
{
	int index;
	int key;
	
	int a[] = {2,5,7,10,12,15,18,22,25,30};
	scanf("%d",&key);
	
	index = search(a,0,sizeof(a)/sizeof(int)-1,key);
	
	if(index< 0) printf("Not Found!\n");
	else printf("[%d] = %d\n",index,a[index]);

	return 0;
} 

int search(int a[],int left,int right,int key)
{
	int mid;
	if(left > right) return -1;
	
	mid = left + (right-left)/2;
	if(key == a[mid]) return mid;
	else if(key > a[mid]){
		return search(a,mid+1,right,key);
	}
	else return search(a,left,mid-1,key);
}
*/








/*
// 指標 + 一維陣列
#include <stdio.h>
//int a[10];
int ans=0;
int  calculate(int * ap,int size);

int main(void)
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	
	ans = calculate(a,10);
	printf("%d\n",ans);
	
	return 0;
} 

int  calculate(int * ap ,int size)
{
	int i;
	for(i=0;i<size;i++){
		//ans = ans + * (ap+i);
		ans = ans + ap[i];
	}
	return ans;
*/










/*
// swap
#include <stdio.h>
int x,y;
int tmp;
void swap(int * x,int * y);

int main(void)
{
	scanf("%d%d",&x,&y);
	swap(&x,&y);
	printf("%d %d\n",x,y);
	return 0;
}

void swap(int * xp,int * yp)
{
	int tmp;
	tmp = * xp;
	* xp = * yp;
	* yp = tmp;
}
*/
