#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* Create_List(Node*, int);
Node* Reverse_List(Node*);
void Print_List(Node*);
void Free_List(Node*);

int main() {
    Node *head = NULL;
    int n, data, i;
    
    scanf("%d", &n);
    for( i=0; i<n; i++ ) {
        scanf("%d", &data);
        head = Create_List( head, data );
    }
    
    head = Reverse_List( head );
    
    Print_List( head );
    Free_List( head );
    
    return 0;
}

Node * tail = NULL;
Node* Create_List(Node* np, int val)
{
	Node * newptr;
	
	newptr = (Node *)malloc(sizeof(Node));
	
	newptr->data = val;
	newptr->next = NULL;
	
	if(np == NULL){
		np = newptr;
		tail = newptr;
	}else{
		tail->next = newptr;
		tail = tail->next;
	}
	
	return np;
}

Node* Reverse_List(Node* np)
{
	Node * currentptr = np;
	Node * preptr = NULL;
	Node * nextptr = NULL;
	
	while(currentptr != NULL){
		nextptr = currentptr->next;
		currentptr->next = preptr;
		preptr = currentptr;
		currentptr = nextptr;
	}
	
	np = preptr;
	return np;
}

void Print_List(Node* np)
{
	Node * currentptr = np;
	
	while(currentptr->next != NULL){
		printf("%d->",currentptr->data);
		currentptr = currentptr->next;
	}
	printf("%d\n",currentptr->data);
}

void Free_List(Node* np)
{
	Node * tmp = NULL;
	Node * current = np;
	
	while(current != NULL){
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
