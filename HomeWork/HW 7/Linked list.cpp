//linked list (由小到大)
#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
	int data;
	struct t_node * next;		//指向自己(Node)的指標 
}Node;

Node * insertlist(Node *np, int val);	//傳進開頭位置 
Node * deletelist(Node *np, int val);
void displist(Node *np); 

int main(void)
{
	Node * head;		//開頭位置 
	head = NULL;
	
	
	head = insertlist(head,8);		//接收回傳的開頭位置 
	displist(head);
	
	head = insertlist(head,10);
	displist(head);
	
	head = deletelist(head,8);
	displist(head);
	  
	return 0;
}

Node * insertlist(Node *np, int val)
{
	Node * newptr, *preptr, *currentptr;		//point
	
	newptr = (Node*)malloc(sizeof(Node));		//產生新的空間 
	
	if(newptr == NULL){
		printf("Out of memory.\n");
		return NULL;		//point
	}
	
	newptr->data = val;
	newptr->next = NULL;		//初始設定
	
	preptr = NULL;
	currentptr = np;	//指向開頭位置 
	
	while(currentptr != NULL && val>currentptr->data){		//!=NULL 代表還沒走到結尾 
		preptr = currentptr;		//point
		currentptr = currentptr->next;
	}
	if(preptr == NULL){		//代表要新加進去的Node就該放在最前面 
		newptr->next = np;
		np = newptr;		//point : 要改開頭的位置 
	}else{
		preptr->next = newptr;
		newptr->next = currentptr;
	}
	
	return np;
}

Node * deletelist(Node *np, int val)
{
	Node * preptr, *currentptr, *tempptr;
	
	if(val == np->data){
		tempptr = np;
		np = np->next;
		free(tempptr);
		return np;
	}
	
	preptr = np;
	currentptr = np->next;
	while(currentptr != NULL && currentptr->data != val){
		preptr = currentptr;
		currentptr = currentptr->next;
	} 
	if(currentptr != NULL){
		tempptr = currentptr;
		preptr->next = currentptr->next;
		free(tempptr);
	}
	
	return np;
}


void displist(Node *np)
{
	//迴圈 
	if(np == NULL){
		printf("List is empty.\n");
	}else{
		printf("Linked list: \n");
		while(np != NULL){
			printf("%d -> ",np->data); 
			np = np->next;		//point
		}
		printf("NULL\n");
	}
}



/*
#include <stdio.h>
#include <string.h>

typedef struct t_node{
	int data;
	struct t_node * next;
}Node;

int main(void)
{
	Node n1,n2;
	
	n1.next = &n2;
	n2.next = &n1;
	
	(*n2.next).data = 10;		//point : 透過n2 去找n1 裡面的data 
	(*n1.next).data = 20;
	
	printf("%d %d",n1.data,n2.data);
	
	return 0;
}
*/
