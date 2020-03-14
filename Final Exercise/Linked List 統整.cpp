//把東西加在後面 
//方法(一) 
void Create_List(Node** head, int data)
{
    if(*head==NULL){
        *head = (Node*)malloc(sizeof(Node));
        (*head)->data = data;
        (*head)->next = NULL;
    }
    else{
        Node* temp = *head;			// temp : 為了不要動到 head 的位置 
        while(temp->next!=NULL) temp = temp -> next;		//point
        Node* new_node = (Node*) malloc(sizeof(Node));
        temp->next = new_node;
        new_node->next = NULL;
        new_node->data = data;
    }
}
//方法(二)
//會用到 tail
void Create_List(Node ** head, Node ** tail, int val)
{
	Node * newptr;
	newptr = (Node *)malloc(sizeof(Node));
	
	newptr->data = val;
	newptr->next = NULL;
	
	if(*head == NULL){
		*head = newptr;
		*tail = newptr;
	}
	else{
		(* tail)->next = newptr;		//會用到 tail 也是為了不要動到 head 的位置 
		*tail = newptr;
	}
}



//把東西加在 '前面'
void push(Node ** head,int val)
{
	Node * newptr;
	newptr = (Node *)mallon(sizeof(Node));
	
	newptr->data = val;
	newptr->next = *head;
	
	*head = newptr;
}



//加東西在特定位置 
Node * insert(Node * head, int val)
{
	Node * newptr;
	Node * pre;
	Node * current;
	newptr = (Node *)malloc(sizeof(Node));
	
	newptr->data = val;
	newptr->next = NULL;
	
	pre = NULL;
	current = head;		//因為每次都要從頭開始檢查 
	
	while(current != NULL && val>current->data){
		pre = current;
		current = current->next;
	}
	
	if(pre == NULL){		//因為可能第二個要放進去的東西要放在開頭 
		newptr->next = head;		//point
		head = newptr;
	}else{
		pre->next = newptr;
		newptr->next = current;		
	}
		
	return head;
} 





 
