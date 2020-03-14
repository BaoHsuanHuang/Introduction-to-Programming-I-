//講義附錄E

#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
	int val;
	struct t_node * next;
}Node;


Node* push(Node *head , int x);
int pop(Node ** hp);
void show(Node * head);

int main(void)
{
	Node * head = NULL;		//point : 要設初始直 = NULL
	
	int x;
	head = push(head,3);
	show(head);

	head = push(head,5);
	show(head);
	
	head = push(head,7);
	show(head);
	x = pop(&head);
	printf("%d\n",x);
	
	show(head);
	
	return 0;
} 

Node* push(Node *h , int x)
{
	Node * q;
	Node * p = (Node *)malloc(sizeof(Node));
	
	p->val = x;
	//p->next = h;
	p->next = NULL;
	
	if(h == NULL) h = p;
	else{
		q = h;
		while(q->next != NULL){
		q = q->next;
		}
		q->next = p;
	}
	
	return p;
}

int pop(Node ** hp)
{
	Node * p = (*hp);
	
	int x;
	
	if(*hp == NULL) return 0;
	
	* hp = p->next;
	x = p->val;
	
	free(p);
	
	return 0;
}

void show(Node * head)
{
	if(head != NULL){
		printf("%d -> ",head->val);
		show(head->next);
	}else{
		printf(".\n");
	}
	
	//也可以改成迴圈版本 
}
