#include <stdio.h>

void f(int *);

int main(void)
{
	int x;
	scanf("%d",&x);
	printf("%d\n",x);
	
	f(&x);		// �ǻ� ��m�� f function 
	
	printf("%d\n",x);
	
	return 0;
}

void f(int * xp)	// xp = &x
{
	*xp = *xp + 1;
}


// __func__ : �|�Q�Ҧb�禡�����N ( ex. main function ) 
// __LINE__ : �N��渹(�ĴX��) ( �� %d ) 
// __TIME__ : show ��ɰ��檺�ɶ� 








#include <stdio.h>

unsigned int mylen(char *);

void f(int *);

int main(void)
{
	int x;
	char str[100];
	int a[100];
	
	scanf("%s",str);
	printf("%s\n",str);
	
	printf("%u\n",mylen(str));
	
	return 0;
}

unsigned int (char * cp);
{
	unsigned int len = 0;
	while (*cp != '\0'){
		cp++;	 // ����U�@�Ӧ�m 
		len++
	}
	
	return len;
}
// ��g 1
unsigned int mylen(char * cp)
{
	char *  startp;		// �ŧi startp ���@ char�������ܼ� 
	startp = cp;
	
		while (*cp != '\0'){
		cp++;	 // ����U�@�Ӧ�m 
	}
	
	return cp-startp;
	
} 
// ��g 2
unsigned int mylen(char * cp)
{
	unsigned int len = 0;
	
	while ( cp[len] != '\0'){	// cp[lne] --> *(cp+len) ���� 
		len++;	 // ����U�@�Ӧ�m 
	}
	
	return len;
	
} 
// �n�`�N char �}�C�O�� '\0' ���� 







#include <stdio.h>

int sum(int *,int);

int main(void)
{
	int n,x,i;
	int a[100];
	char *cp;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);	// &a[i]  -->  a+i
		// ��z : &a[i]  -->  & *(a+i)  -->  a+i 	// & �M * ���۩�P 
	}
	
	cp = (char *) a;	// �j���ഫ���O 	// �N�i�H���O�L�X int �� 4�� bytes ���� 
	printf("%d %d %d %d\n",cp[0],cp[1],cp[2],cp[3]);
	
	printf("%d\n",sum(a,n));
	
	return 0;
} 

int sum(int * xp,int n)
{
	int ans;
	
	while(n>0){
		ans = ans + *xp;
		xp++;
		n--;
	}
	return ans;
}
//��g
int sum(int b[],int n)
{
	int i,ans;
	for(i=0,ans=0;i<n;i++){
		ans += b[i];	//	b[i]  -->  *b
	}
	
	return ans;
}







#include <stdio.h>

int main(void)
{
	int x;
	
	int *   xp;

	/*	��l��:
	xp = &x;	*/ 

	*xp = 100;		// �����D : �]���|����l��(�٤����D xp �쩳�b����)�N�h���ܥ����� --> ���i��|�� 
	
	return o;
} 












