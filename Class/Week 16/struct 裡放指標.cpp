#include <stdio.h>

typedef struct t_node{
	int val;
	struct t_node * next;
}Node;

int main(void)
{
	Node * head;
	
	head = (Node * )malloc(sizeof(Node));
	head->head = 100;
	head->next = (Node*)malloc(sizeof(Node));
	
	(head->next)->val = 200;
	(head->next)->next = NULL;
	
	return 0;
}



#include <stdio.h>
#include <stdlib.h>

typedef struct _Block{
	int x;
	int y;
	double z;
	struct _Block *next;	//struck 裡的 struck 必須要是指標 
}Block;

int main(void)
{
	Block b1,b2,b3;
	
	b1.x = 5;
	b1.y = 10;
	b1.z = 0.2;
	b1.next = &b2;		// 透過b1去找b2的位置 
	
	b2.next = &b3;
	
	b3.next = NULL;
	
	(*(b1.next)).x = 100;		// 注意括號 
	
	printf("%d\n",b2.x);
	
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

typedef struct _Block{
	int x;
	int y;
	double z;
	struct _Block *next;	//struck 裡的 struck 必須要是指標 
}Block;

int main(void)
{
	Block b1,b2,b3;
	Block *p;
	
	b1.x = 5;
	b1.y = 10;
	b1.z = 0.2;
	b1.next = &b2;		// 透過b1去找b2的位置 
	b2.x = 500;
	b2.next = &b3;
	b3.x = 5000;
	b3.next = NULL;
	
	p = &b1;
	
	while(p!=NULL){
		printf("%d\n",p->x);
		p = p->next;
	}
	
	return 0;
}











