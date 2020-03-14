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

Node* Create_List(Node* head, int val)
{
	Node * newptr;
	newptr = (Node *)malloc(sizeof(Node));
	
	newptr->data = val;
	newptr->next = NULL;
	
	if(head == NULL){
		head = newptr;
	}
	else{
		Node * tmp = head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = newptr;
	}
	return head;
}

Node* Reverse_List(Node* head)
{
	Node * pre;
	Node * current;
	Node * tmp;
	
	pre = NULL;
	current = head;
	tmp = NULL;
	
	while(current!=NULL){		//point
		tmp = current->next;
		current->next = pre;
		pre = current;
		current = tmp;
	}
	
	head = pre;			//point
	
	return head;
}

void Print_List(Node* head)
{
	Node * tmp;
	tmp = head;
	while(tmp->next!=NULL){
		printf("%d->",tmp->data);
		tmp = tmp->next;
	}
	printf("%d\n",tmp->data);
}

void Free_List(Node* head)
{
	Node * tmp;
	while(head!=NULL){
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
