���q��10�� p.14 15 
#include <stdio.h>

int sum(int * a,int n);		// int * a  ==  int a[]
// int sum(int [] , int n)
// int sum(int * , int n)

int main(void)
{
	int b[] = {1,2,3,4,5};
	printf("%d\n",sum(b,5));
	
	int x;
	char c;
	
	
	void * vp;		// �S���w�]���O������ 
	vp = &x; 
	vp = &c;	// ��̬Ҧ���
	* ( (int *)vp )  = 100000;
	* ( (char *)vp ) = 'A';
	
	
	int * xp;
	char * cp;
	xp = &x;
	cp = &c;
	
	printf("&x : %p\n",&x);
	printf("&c : %p\n",&c);
	
	return 0;
}

int sum(int * a,int n)
{
	int ans=0;
	for(int i=0;i<n;i++){
		ans += a[i];
	}
	
	return ans;
}





���q��10�� p.16~18
#include <stdio.h>

void show_int_array(int [],int);

int main(void)
{
	int arr[4] = {100,200,300,400};
	int * ptr1, * ptr2;		// point
	
	ptr1 = arr;		// ptr1 = &arr[0] �۵� 		// ���O���}�C���}�Y��m 
	ptr2 = &arr[3];
	
	show_int_array(arr,4);
	
	return 0;
} 

void show_int_array(int a[],int n)
{
	int * ip;
	for(ip = a; ip<(a+n) ; ip++){
		printf("|%p",ip);
	}
	/*for(int i=0;i<n;i++){
		printf("%p ", &a[i]);
	} */
	printf("|\n");
	for(ip = a; ip<(a+n) ; ip++){
		printf("|%14d", *ip);
	}
	printf("|\n");
}






���q��10�� p,18 19
#include <stdio.h>

void show_2d_int_array(int (*zp)[2], int );		// point : 2d �}�C���ŧi�覡 		// int (*zp) []  --> int [] [2]
												// �@�w�n�� 2 �N���Ӿ�Ƥ@��				
int main(void)
{
	int z[4] [2] = {{1,2},{3,4},{5,6},{7,8}};
	int (*zp) [2];		// point : �n�[�A�� 
	zp = z;
	// ��G���}�C�����@���}�C 
	// z[4] ���@���}�C �A ���̭��s [2]����Ӥ���
	/*
	1  2  --> z[0]
	3  4  --> z[1]
	5  6  --> z[2]
	7  8  --> z[3]
	*/
	
	
	/// ���άA��
	int *  zp[5]; 		// ���а}�C 
	zp[0] = &z[0][0];
	zp[1] = &z[1][0];
	zp[2] = &z[2][0];
	zp[3] = &z[3][0];
	zp[4] = &z[4][0];
		// for �j���g 
	for(int i=0;i<5;i++){
		zp[i] = &z[i][0];		// zp[i] = &z[(i+1)%5] [0]   �ܦ� zp[0][0] �� 3 
	}
	printf("%d\n",zp[3][1]);
	///
	
	printf("z: %p\n",z);
	printf("z[0]: %p\n",z[0]);		// point : z[0] show �X  1 2 ���}�Y��m 
	//�ۦP printf("&z[0][0]: %p\n",&z[0][0]);		// point : �n�[ &
	
	printf("z+1: %p\n",z+1);		// �]�� z[1] --> show �X 3 4 ���}�Y 
	printf("z[0]+1: %p\n",z[0]+1); 		// �]�� z[0][1]  --> show �X 2 ����m
	
	/*
	z[0]+1
	== &* z[0]+1
	== &  *(z[0]+1) 
	== & z[0][1]
	*/
	
	int a[4] = {1,2,3,4}; 
	int * ap;
	ap = a;
	
	
	show_2d_int_array(z,4);
	
	return 0;
} 

void show_2d_int_array(int (*zp) [2] , int n)		// int (*zp) [2]  --> int z[] [2]
{
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			printf("%d ",zp[i] [j]);		// point : zp
		}
		printf("\n");
	}
}






