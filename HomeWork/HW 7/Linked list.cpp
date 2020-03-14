//linked list (�Ѥp��j)
#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
	int data;
	struct t_node * next;		//���V�ۤv(Node)������ 
}Node;

Node * insertlist(Node *np, int val);	//�Ƕi�}�Y��m 
Node * deletelist(Node *np, int val);
void displist(Node *np); 

int main(void)
{
	Node * head;		//�}�Y��m 
	head = NULL;
	
	
	head = insertlist(head,8);		//�����^�Ǫ��}�Y��m 
	displist(head);
	
	head = insertlist(head,10);
	displist(head);
	
	head = deletelist(head,8);
	displist(head);
	  
	return 0;
}

Node * insertlist(Node *np, int val)
{
	Node * newptr, *preptr, *currentptr;		//point
	
	newptr = (Node*)malloc(sizeof(Node));		//���ͷs���Ŷ� 
	
	if(newptr == NULL){
		printf("Out of memory.\n");
		return NULL;		//point
	}
	
	newptr->data = val;
	newptr->next = NULL;		//��l�]�w
	
	preptr = NULL;
	currentptr = np;	//���V�}�Y��m 
	
	while(currentptr != NULL && val>currentptr->data){		//!=NULL �N���٨S���쵲�� 
		preptr = currentptr;		//point
		currentptr = currentptr->next;
	}
	if(preptr == NULL){		//�N��n�s�[�i�h��Node�N�ө�b�̫e�� 
		newptr->next = np;
		np = newptr;		//point : �n��}�Y����m 
	}else{
		preptr->next = newptr;
		newptr->next = currentptr;
	}
	
	return np;
}

Node * deletelist(Node *np, int val)
{
	Node * preptr, *currentptr, *tempptr;
	
	if(val == np->data){
		tempptr = np;
		np = np->next;
		free(tempptr);
		return np;
	}
	
	preptr = np;
	currentptr = np->next;
	while(currentptr != NULL && currentptr->data != val){
		preptr = currentptr;
		currentptr = currentptr->next;
	} 
	if(currentptr != NULL){
		tempptr = currentptr;
		preptr->next = currentptr->next;
		free(tempptr);
	}
	
	return np;
}


void displist(Node *np)
{
	//�j�� 
	if(np == NULL){
		printf("List is empty.\n");
	}else{
		printf("Linked list: \n");
		while(np != NULL){
			printf("%d -> ",np->data); 
			np = np->next;		//point
		}
		printf("NULL\n");
	}
}



/*
#include <stdio.h>
#include <string.h>

typedef struct t_node{
	int data;
	struct t_node * next;
}Node;

int main(void)
{
	Node n1,n2;
	
	n1.next = &n2;
	n2.next = &n1;
	
	(*n2.next).data = 10;		//point : �z�Ln2 �h��n1 �̭���data 
	(*n1.next).data = 20;
	
	printf("%d %d",n1.data,n2.data);
	
	return 0;
}
*/
