#include <stdio.h>

char str[100]; // 0x10cde3020

int main(void)
{
	//scanf("%s",str);
	printf("%p\n",str);
	
	//long long ss;
	char * ss;	 // ss : ����(�ܼ�) 
	// ���� = �@�ӥi�H�Ψ��x�s�O�����m���ܼ� 
	// (type) * �ܼƦW�� 
	ss = str;	// �O��O���骺��m 
	//printf("%#llx\n",ss);
	printf("%p\n",ss);
	
	return 0;
}









#include <stdio.h>

char str[100];

int main(void)
{
	scanf("%s",str);
	
	char * ss;
	ss = str;
	
	printf("%s\n",str);
	
	ss++;	// �ܦ��O����ĤG�Ӧ�m��char 
	*ss = 'Z';	// ���ܰO�����m�Ĥ@�Ӫ�char 
	// ���i�H���� str++ �A �]�� str �O�@�Ӱ}�C�W�� 
	printf("%s\n",str);
	
	printf("%s\n",str);
	printf("%c\n",str[2]);	== printf("%c\n",ss[2]);  == printf("%c\n",2[str]);
	printf("%c\n",*(ss+2));  == printf("%c\n",*(str+2));  == printf("%c\n",*(2+ss));

	
	// �Y ss = ss + 2
	// �i�H printf("%c\n",str[-2]);  == printf("%c\n",*(ss-2));		// index �i�H�O�t�� 
	
	
	return 0;
	
}










#include <stdio.h>
int a[100];
char str[100];

int main(void)
{
	int * ap;
	ap = a;
	
	char * ss;
	ss = str;
	
	printf("%p\n",ap);
	printf("%p\n",ap+1);	// �M ap �t 4 �A �]�� int �� 4��bytes 
	
	printf("%p\n",ss);
	printf("%p\n",ss+1);	// �M ss �t 1 �A �]�� char �� 1��bytes 
	
	// double �t 8��bytes 
	
	printf("%ld %ld",sizeof(ss),sizeof(ap));	// �o��Ҭ� 8bytes�A�]�����P���X���j�p���O�@�˪� 
	
	ss++;
	*ss = 'Z';


	
	
	return 0;
}





