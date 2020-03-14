//Sorting 2D array
#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

int compare (const void *pa, const void *pb);

int main(void){
    int **array;
    int i, number;

    scanf("%d", &number);

    /** Dynamically create 2d array **/
    array = (int **)malloc(number * sizeof(int*));
    for (i = 0; i < number; i++){
        array[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d %d", &array[i][0], &array[i][1]);
    }

    qsort(array, number, sizeof array[0], compare);

    for(i = 0; i < number; ++i)
        printf("%3d %3d\n", array[i][0], array[i][1]);

    return 0;
}

int compare (const void *pa, const void *pb)
{
	int ** va = (int **)pa;
	int ** vb = (int **)pb;
	
	if((*va)[0] > (*vb)[0]) return 1;
	else if((*va)[0] < (*vb)[0]) return -1;
	else{
		if((*va)[1] > (*vb)[1]) return 1;
		else if((*va)[1] < (*vb)[1]) return -1;
		else return 0;	
	}
}


//Delete Last Node
#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void Create_List(Node**, int);
Node* Delete_Last_Node(Node*);
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
    
    Node *head = Delete_Last_Node(head_a);
    Print_List(head);
    Free_List(head);
    
    return 0;
}

void Create_List(Node** head, int val)
{
	Node * newptr = (Node *)malloc(sizeof(Node));
	
	newptr->data = val;
	newptr->next = NULL;
	
	if(*head==NULL){
		*head = newptr;
	}else{
		Node * tmp = *head;
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
		tmp->next = newptr;
	}
}

Node* Delete_Last_Node(Node* head)
{
	Node * pre;
	Node * current;
	
	pre = NULL;
	current = head;
	
	while(current->next != NULL){
		pre = current;
		current = current->next;
	}
	pre->next = NULL;
	free(current);		//point
	
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
	while(head != NULL){
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

