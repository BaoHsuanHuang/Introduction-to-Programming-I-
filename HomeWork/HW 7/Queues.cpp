#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
	int data;
	struct t_node * next;
}Node;

void printQueue(Node * currentptr);
void enqueue(Node ** head, Node ** tail , int val);
int dequeue(Node ** head, Node ** tail);	//回傳被刪除的Node裡面的data 

int main(void)
{
	Node * head;
	Node * tail;
	
	head = NULL;
	tail = NULL;
	
	enqueue(&head, &tail, 4);
	printQueue(head);
	enqueue(&head, &tail, 8); 
	printQueue(head);
	enqueue(&head, &tail, 10); 
	printQueue(head);
	enqueue(&head, &tail, 2); 
	printQueue(head);
	
	printf("%d is out.\n\n",dequeue(&head,&tail));
	printQueue(head);
	
	return 0;
}

void printQueue(Node * currentptr)
{
	if(currentptr == NULL){
		printf("The queue is empty.\n");
	}else{
		printf("Queue : \n");
		while(currentptr != NULL){
			printf("%d->",currentptr->data);
			currentptr = currentptr->next;
		}
		printf("NULL\n\n");
	}
}

// 加東西在後面 
void enqueue(Node ** head, Node ** tail , int val)
{
	Node * newptr;
	newptr = (Node *)malloc(sizeof(Node));
	
	if(newptr == NULL){
		printf("Out of memory.\n");
	}else{
		newptr->data = val;
		newptr->next = NULL;
		if(*head == NULL){
			*head = newptr;
			*tail = newptr;
		}else{
			(*tail)->next = newptr;
			*tail = newptr;
		}
	}
	
}

//移除前面的東西 
int dequeue(Node ** head, Node ** tail)
{
	int val;
	Node * tmp;
	
	if(*head == NULL) return -1;
	val = (*head)->data;
	
	tmp = *head;
	*head = (*head)->next;
	
	if(*head == NULL){
		*tail = NULL;
	}
	free(tmp);
	
	return val;
	
}

