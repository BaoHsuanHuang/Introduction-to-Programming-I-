#include <stdio.h>
#include <string.h>    //string.h �r�ꪺ���   //char array : �r���}�C 
#define AMY 123.45678  //���w�q�nAMY 
int main(void)
{
	char x;
	
	x = 'A' ;
	//�Yx = '7' �ä��O�N��Ʀr7�A�ӬO�r�� 
	//x���൥��560  �]��char���d��:-128~127(8�줸) 
	printf("%d",x);   //show 65(�G�i�쬰1000001) 
	printf("%c",x);
	printf("%#x",x);  //16�i���ܦr��A���ƭ� 
	
	x = '7';
	printf("%c",x-'0');  //'7' - '0'�N�� 55-48
	
	scanf("%c",&x); //scanf�i�f�t %c(���ܤ֥�) 
	//�Y��J 7 �N���O�r��(%c)
	
	
	char name[10];
	scanf("%s",name);  //char��scanf �W�h(name�������N�q�N�O�@�ӪŶ��B�ҥH���Υ[&) 
	printf("%s",name); //%s�O�r����   //�O���餤����ƭ� 0 �A�t�W %s �N���� 
	printf("%c",name[2]); // %c show �X��@�S�w�r��(name[2])
	//name[0].name[1].....�q0�}�l
	printf("%p",name);  //show�Xname�b�O���骺��m
	printf("%p",&name[1]); //�ݭn�[ & 
	
	//�O���餤����ƭ� 0 �A�t�W %s �N���� 
	scanf("%s",name);  //��JTommy 
	name[2] = 0; �άO name[2] = '\0'; 
	printf("%s",name);  //�u�|��XTom
	
	printf("the length of %s is %d",name,strlen(name));
	printf("the number of characters in %s is %d",name,strlen(name));  //�Y�r���ƫܪ��A�i�� %u(unsigned int) 
	
	scanf("%9s",name);  //�i�H�����J���r���� 
	
	#define border "##########################"  //define �� ""�N�����޸����O�r�� 
	cahr word[26];
	scanf("%25s",word);
	printf("") �ݤ����photo 
	
	
	printf("%s %s\n",__DATE__,__TIME__);
	printf("%s %s %d\n",__func__,__FILE__.__LINE__);
	
	return 0;
 } 
