#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
	int data;
	struct t_node * next;
}Node;

void printStack(Node *currentptr);
void push(Node* *topptr, int val);
void pop(Node **topptrptr);		//�^�ǭn�Q�R����Node�̪���� 

int main(void)
{
	Node * stackptr = NULL;
	
	push(&stackptr, 42);		//point : �Y���n�Ǧ^�ȡA�N�n���m�Ƕi�h 
	printStack(stackptr);
	
	push(&stackptr,32);
	printStack(stackptr);
	
	push(&stackptr,20);
	printStack(stackptr);
	
	//printf("pop: %d\n",pop(&stackptr));
	pop(&stackptr);
	printStack(stackptr);
	
	return 0;
}


void push(Node* *topptrptr, int val)
{
	Node * newptr;
	
	newptr = (Node *)malloc(sizeof(Node));
	
	if(newptr == NULL){
		printf("Out of memory.\n");
	}
	else{
		newptr->data = val;
		newptr->next = *topptrptr;		//point
		*topptrptr = newptr;		//�����ק�����}�Y��m�������ܼ� 
	}
	
}

void pop(Node **topptrptr)
{
	Node * tempptr;
	int popvalue;
	
	//if(*topptrptr == NULL) return -1;		//�L�k���X����F�� 
	
	tempptr = *topptrptr;
	*topptrptr = (*topptrptr)->next;
	popvalue = tempptr->data;
	
	free(tempptr);
	
	//return popvalue;
	
}


void printStack(Node *currentptr)
{
	if(currentptr == NULL){
		printf("Nothing.\n");
	}
	else{
		printf("Stack: \n");
		while(currentptr != NULL){
			printf("%d -> ",currentptr->data);
			currentptr = currentptr->next;
		}
		printf("NULL.\n"); 
	}
}
