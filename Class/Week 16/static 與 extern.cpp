/*
static

��ƫe���p�G�[ static 
��ܳo�Ө�Ƥ��|�Q linker �ݨ�
�]�����|�M��L�ɮ׳s��

�ܼƫe���p�G�[ static
��ܳo���ܼƱq�{���}�l����N�|�s�b
����{�������~�|����

extern

�u�b�@�ӭ�l�X�ɮפ��w�q
int x = 0;
��L��l�X�ɮצp�G�ϥ� x�A���ӫŧi��
extern int x
*/
#include <stdio.h>
#include <stdlib.h>
int f(void)
{
	static int x=0;
	x = x+1;
	return x;
}

int main(void)
{
	printf("%d\n",f());
	printf("%d\n",f());
	printf("%d\n",f());
	printf("%d\n",f());
	printf("%d\n",f());
	
	return 0;
}
