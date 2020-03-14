#include <stdio.h>
#include <stdlib.h>
typedef struct monkey{
	char c;
	struct monkey *prev;
	struct monkey *next;
}Monkey;
int main(void){
	char c;
	Monkey *node=(Monkey *)malloc(sizeof(Monkey));
	Monkey *head=(Monkey *)malloc(sizeof(Monkey));
	Monkey *t;
	node->next=NULL;
	node->prev=NULL;
	head->prev=NULL;
	head->next=NULL;
	while((c=getchar())!=EOF){
		if(c=='D'){
			if(node->next==NULL){
			}
			else if(node->next==head->next){
				t=node->next;
				if(node->next->next==NULL){
					head->next=NULL;
					node->next=NULL;
					free(t);
				}
				else{
					head->next=node->next->next;
					head->next->prev=NULL;
					node->next=head->next;
					free(t);
				}
			}
			else{
				t=node->next;
				if(node->next->next==NULL){
					t->prev->next=NULL;
					node->next=NULL;
					free(t);
				}
				else{
					t->prev->next=t->next;
					t->next->prev=t->prev;
					node->next=t->next;
					free(t);
				}
			}
		}
		else if(c=='>'){
			if(node->next==NULL){
			}
			else{
				
				node->prev=node->next;
				node->next=node->next->next;
				
			}
		}
		else if(c=='<'){
			if(node->prev==NULL){
			}
			else{
				
				node->next=node->prev;
				node->prev=node->prev->prev;
				
			}
		}
		else if(c!='\n'){
			Monkey *p=(Monkey *)malloc(sizeof(Monkey));
			p->next=NULL;
			p->prev=NULL;
			p->c=c;
			if(node->prev==NULL){
				if(node->next==NULL){
					head->next=p;
					node->prev=p;
				}
				else{
					head->next=p;
					node->next->prev=p;
					p->next=node->next;
					p->prev=NULL;
					node->prev=p;
				}
			}
			else{
				if(node->next==NULL){
					node->prev->next=p;
					p->prev=node->prev;
					p->next=NULL;
					node->prev=p;
				}
				else{
					node->prev->next=p;
					node->next->prev=p;
					p->next=node->next;
					p->prev=node->prev;
					node->prev=p;
				}
			}
		}
	}
	node=head->next;
	while(node->next!=NULL){
		printf("%c",node->c);
		node=node->next;
	}
	printf("%c\n",node->c);
}
