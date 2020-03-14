#include <stdio.h>

void show(void);//事先宣告函數的形式給main 

int main(void)
{
	show();    //跳到 void show 執行 
	return 0;
}

void show(void)
{
	//程式碼 
}



#include <stdio.h>

void show(int,double);

int main(void)
{
	show(1,3.2);    //跳到 void show 執行 完 在執行下一個show 
	show(2,3.4);
	return 0;
}

void show(int x)
{
	//程式碼
	printf("Hello %f\n",x*y); 
}
//可以在 show 裡面printf  也可以在show裡面得到一個值傳回main，在main裡面printf



#include<stdio.h> 

double f(int,double);

int main(void)
{
	double z;
	z = f(1,2.3);
	return 0;
}

double f(int x,double y)
{
	double ans;
	ans = x*y;
	printf("%f\n",ans);
	return ans; //因為為double f ()，所以要有回傳值 
}




#include <stdio.h>

void f(int);

int main(void)
{
	f(1);
	return 0;
} 
 
void f(int x)
{
	if (x<10){
		f(x+1);
		printf("%d\n",x);
	}
	// x =1, 呼叫f(2)  hold  printf("%d\n",1)
	// x =2, 呼叫f(3)  hold  printf("%d\n",2)
	//.
	//.
	// x =8, 呼叫f(9)  hold  printf("%d\n",8)
	// x =9, 呼叫f(10)  hold  printf("%d\n",9)   因為到f(10)函式呼叫結束 
}




#include <stdio.h>

int f(int);
int main(void)
{
	
	printf("%d\n",f(10)); //交給其他函式去算，再給我答案 
	
	return 0;
}

int f(int x)
{
	int ans;
	if (x>0){
		ans = x + f(x-1); // point     //到最後只要去思考我要的f(10) = 10+f(9)即可 ，f(9)是已知的(因為電腦可以幫我算) 
		printf("%d\n",x);
	}
	else{
		ans =0;
	}
	return ans;
}
//f(x) = 0 if x<=0   otherwise  f(x) = x+f(x-1)    




//example
#include<stdio.h>
void power(double,int);

int main(void){
	printf("%f\n",power(1.6,3));
	return 0;
}

void power(double n,int p)
{
	double ans;
	if(p>0){
		ans = n*power(n,p-1);
	}
	else{
		ans = 1;
	}
	return ans;
}
//example
#include<stdio.h>
void power(double,int);

int main(void){
	printf("%f\n",power(1.6,3));
	return 0;
}

void power(double n,int p)
{
	double ans;
	if(p>0){
		ans = n*power(n,p/2);  //當p為偶數的時候 
		ans = ans*ans;
		if(p%2) {  //p為奇數 
			ans = n*ans; 
		}
	}
	else{
		ans = 1; //p=0的答案 
	}
	return ans;
}


// finish week 7 enamples //


//example 2
#include <stdio.h>
int f(int);

int main(void)
{
	printf(" = %d\n",f(10));
	return 0;
}

int f(int x)
{
	int ans;
	if (x>1){
		if(x%2==0){
			printf("( ");
		}
		ans = f(x-1);
		if(x%2){
			printf("*%d",x);
			ans = ans*x;
		}
		else{
			printf("+%d",x);
			ans = ans+x;
		}
		
		if(x%2 == 0){
			printf(") ");
		}
		else{
			printf("%d",x);
			ans = 1;
		}
		
	}
	return ans;
}



//example最大公因數 
#include <stdio.h>

int gcd(int,int);

int main(void)
{
	printf("%d\n",gcd(21,105));
	return 0;
}

int gcd(int a;int b)
{
	if(b==0){
		return a;
	}
	return gcd(b,a%b); //剛開始a=21，b=105進入，得到gcd(105,21) ，此時的a=105，b=21 
 } 

  
