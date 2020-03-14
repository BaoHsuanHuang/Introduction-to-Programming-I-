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

void Create_List(Node** head, int val)
{
	Node * newptr;
	newptr = (Node *)malloc(sizeof(Node));
	
	newptr->data = val;
	newptr->next = NULL;
	
	if(*head == NULL){
		*head = newptr;
	}
	else{
		Node *tmp= *head;
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
		tmp->next = newptr;
	}
}

Node* Add_List(Node* head_a, Node* head_b)
{
	Node * head = NULL;		//相加陣列的開頭     //point : 要設NULL 
	Node * ha = head_a;			//因為之後還會用到head_a和head_b所以不能動到他們的位置 
	Node * hb = head_b;
	
	while(ha!=NULL && hb!=NULL){
		Create_List(&head, ha->data + hb->data);
		ha = ha->next;
		hb = hb->next;
	}
	if(ha == NULL){
		while(hb!=NULL){		//point
			Create_List(&head,hb->data);
			hb = hb->next; 
		}
				
	}
	else if(hb == NULL){
		while(ha!=NULL){		//point
			Create_List(&head, ha->data);
			ha = ha->next;
		}
	}
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
	//tmp = head;
	while(head != NULL){
		tmp = head;
		
		head = head->next;
		free(tmp);		//point
	}
}

