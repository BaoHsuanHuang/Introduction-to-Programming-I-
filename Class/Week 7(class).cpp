#include <stdio.h>

void show(void);//�ƥ��ŧi��ƪ��Φ���main 

int main(void)
{
	show();    //���� void show ���� 
	return 0;
}

void show(void)
{
	//�{���X 
}



#include <stdio.h>

void show(int,double);

int main(void)
{
	show(1,3.2);    //���� void show ���� �� �b����U�@��show 
	show(2,3.4);
	return 0;
}

void show(int x)
{
	//�{���X
	printf("Hello %f\n",x*y); 
}
//�i�H�b show �̭�printf  �]�i�H�bshow�̭��o��@�ӭȶǦ^main�A�bmain�̭�printf



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
	return ans; //�]����double f ()�A�ҥH�n���^�ǭ� 
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
	// x =1, �I�sf(2)  hold  printf("%d\n",1)
	// x =2, �I�sf(3)  hold  printf("%d\n",2)
	//.
	//.
	// x =8, �I�sf(9)  hold  printf("%d\n",8)
	// x =9, �I�sf(10)  hold  printf("%d\n",9)   �]����f(10)�禡�I�s���� 
}




#include <stdio.h>

int f(int);
int main(void)
{
	
	printf("%d\n",f(10)); //�浹��L�禡�h��A�A���ڵ��� 
	
	return 0;
}

int f(int x)
{
	int ans;
	if (x>0){
		ans = x + f(x-1); // point     //��̫�u�n�h��ҧڭn��f(10) = 10+f(9)�Y�i �Af(9)�O�w����(�]���q���i�H���ں�) 
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
		ans = n*power(n,p/2);  //��p�����ƪ��ɭ� 
		ans = ans*ans;
		if(p%2) {  //p���_�� 
			ans = n*ans; 
		}
	}
	else{
		ans = 1; //p=0������ 
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



//example�̤j���]�� 
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
	return gcd(b,a%b); //��}�la=21�Ab=105�i�J�A�o��gcd(105,21) �A���ɪ�a=105�Ab=21 
 } 

  
