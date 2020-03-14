#include <stdio.h>
#include <stdlib.h>
//#include "function.h"


typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void Create_List(Node**, int);
Node* Add_List(Node*, Node*);
void Print_List(Node*);
void Free_List(Node*);


int main() {
    Node *head_a = NULL, *head_b = NULL;
    int data;

    while(1) { // read List a
        scanf("%d", &data);
        if (data >= 0) {
          Create_List(&head_a, data);
        } else break;
    }
    while(1) { // read List b
        scanf("%d", &data);
        if (data >= 0) {
          Create_List(&head_b, data);
        } else break;
    }
    
    Node *head = Add_List( head_a, head_b );
    
    Print_List( head_a );
    Print_List( head_b );
    Print_List( head );
    
    Free_List( head_a );
    Free_List( head_b );
    Free_List( head );
    
    return 0;
}


Node * tail = NULL;		//紀錄字串結尾位置 
void Create_List(Node** np, int data)
{
	Node * newptr  = (Node *)malloc(sizeof(Node));
	
	newptr->data = data;
	newptr->next = NULL;
	
	if(*np == NULL){
		*np = newptr;
		tail = newptr;
	}else{
		tail->next = newptr;
		tail = newptr;
	}
}

Node* Add_List(Node* head_a, Node* head_b)
{
	Node * h = NULL;
    // creat_list 是看傳進去的head值是不是NULL來決定要新建或延長
    Node * ha = head_a;
    Node * hb = head_b;
    
    while (ha != NULL && hb != NULL) {
        Create_List(&h, ha->data + hb->data);
        ha = ha->next;
        hb = hb->next;
    }
	if (ha == NULL) {
        while (hb != NULL) {
            Create_List(&h, hb->data);
            hb = hb->next;
        }
    }
    else if (hb == NULL) {
        while (ha != NULL) {
            Create_List(&h, ha->data);
            ha = ha->next;
        }
    }

    return h;
}

void Print_List(Node* head)
{
	Node * currentptr = head;
	while(currentptr->next != NULL){
		printf("%d->",currentptr->data);
		currentptr = currentptr->next;
	}
	printf("%d\n",currentptr->data);	
}

void Free_List(Node* head)
{
	Node * tmp;
	Node * current = head;
	
	while(current != NULL){
		tmp = current;
		//free(current);
		//current = tmp->next;
		
		current = current->next;
		free(tmp);
	}
}
