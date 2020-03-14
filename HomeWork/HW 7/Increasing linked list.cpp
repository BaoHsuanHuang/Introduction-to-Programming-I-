#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void insert_increase_list(Node**, int);

void printList(Node *head);
void freeList(Node*);

int main() {
	Node *head = NULL;
	Node *temp;
	int data;

	while(1){
		scanf("%d", &data);
		if (data >= 0) {
			insert_increase_list(&head, data);
		} else break;
	}

	printList(head);
	freeList(head);
	return 0;
}

void insert_increase_list(Node** head, int val)
{
	Node * newptr;
	Node * pre, * current;
	
	newptr = (Node *)malloc(sizeof(Node));
	
	newptr->data = val;
	newptr->next = NULL;
	
	pre = NULL;
	current = *head;
	
	while(current != NULL && val>current->data){
		pre = current;
		current = current->next;
	}
	if(pre == NULL){
		newptr->next = *head;
		*head = newptr;
	}
	else{
		pre->next = newptr;
		newptr->next = current;
	}
	
}

void freeList(Node *head)
{
	Node *temp;
	for(temp=head; temp!=NULL; temp=head)
	{
		head = head->next;
		free(temp);
	}
}

void printList(Node *head)
{
	Node *temp;
	for(temp = head; temp!=NULL; temp=temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}
