/*#include <stdio.h>
int rectangle(int width,int height,char x);

int main(void){
	int width,height,A;
	char x;
	int i;
	
	for(i=0;i<2;i++){
		scanf("%d%d",&width,&height);
		scanf("%c",&x);
		//印出長方形
		
		A = rectangle(width,height,x);
		printf("%d\n",A);
	}
	
	return 0;
}

int rectangle(int width,int height,char x)
{
	int i,j;
	int ans;
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			printf("%c",x);
		}
		printf("\n");
	}
	ans = width*height;
	return ans;
}*/
/*#include <stdio.h>
int rectangle(int width,int height,char x);

int main(void){
	int width,height,A;
	char x;
	int i;
	
	for(i=0;i<2;i++){
		scanf("%d%d",&width,&height);
		scanf("%c",&x);
		rectangle(width,height,x);
		//印出長方形
		//A =  rectangle(width,height,x);
		//printf("%d\n",A);
	}
	return 0;
}

void rectangle(int width,int height,char x)
{
	int i,j;
	int ans;
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			printf("%c",x);
		}
		printf("\n");
	}
	ans = width*height;
	printf("%d",ans);
}
*/
/*
#include <stdio.h>
double power(double n,unsigned int p);
int main(void)
{
	double n;
	unsigned p;
	
	scanf("%lf%d",&n,&p);
	
	printf("%lf\n",power(n,p));
	
	return 0;
}

double power(double n,unsigned int p)
{
	double ans;
	if(p==0) return 1;
	ans = power(n,p/2);
	if(p%2==0) return ans*ans;
	else return ans*ans*n;
}
*/

/* 
//九九乘法表 
#include <stdio.h>
int main(void)
{
	int i,j;
	
	for(i=1;i<=9;i++){
		for(j=1;j<i;j++){
			printf("   ");
		}
		for(;j<=9;j++){
			printf("%3d",i*j);
		}
		printf("\n");
	}
	return 0;
}
*/


/*
//空心的長方形
#include <stdio.h>
int main(void)
{
	int a,b,c;
	int i;
	scanf("%d%d%d",&a,&b,&c);
	for(i=1;i<=a;i++){
		for(j=1;j<=c;j++){
			printf("*");
		}
		printf("\n");
		for(;j<=b-c;++){
			printf( )
		}
		
		
		
		
		printf("\n");
	}
	return 0;
 } 
*/



//最大公因數
/*x    y
105  63
         x%y  
105%63 = 42
y  x%y
63%42 = 21
42%21 = 0
*/
#include <stdio.h>
int function(int a,int b);

int main(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",function(a,b));
	
	return 0;
}

int function(int a,int b)
{
	int ans;
	if (a%b == 0){
		ans = b;
	}else{
		ans = function(b,a%b);
	}
	return ans;
}


















 











