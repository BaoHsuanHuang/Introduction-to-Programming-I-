#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

int n=0;
void Create_List(Node**, int);
Node* Delete_Middle_Node(Node*);
void Print_List(Node*);
void Free_List(Node*);

int main() {
    Node *head_a = NULL;
    int data;

    while(1) { // read List a
        scanf("%d", &data);
        if (data >= 0) {
          Create_List(&head_a, data);
        } else break;
    }
    
    Node *head = Delete_Middle_Node(head_a);
    Print_List(head);
    Free_List(head);
    
    return 0;
}

void Create_List(Node** head, int val)
{
	n++;
	
	Node * newptr;
	newptr = (Node *)malloc(sizeof(Node));
	
	newptr->data = val;
	newptr->next = NULL;
	
	if(*head == NULL){
		*head = newptr;
	}else{
		Node * tmp = *head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = newptr;
	}	
}

Node* Delete_Middle_Node(Node* head)
{
	Node * pre;
	Node * current;
	int i;
	
	pre = NULL;
	current = head;
	

	for(i=0;i<n/2;i++){
		pre = current;
		current = current->next;
	}
	pre->next = current->next;
	
	return head;
}

void Print_List(Node* head)
{
	Node * tmp;
	tmp = head;
	
	while(tmp->next != NULL){
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


