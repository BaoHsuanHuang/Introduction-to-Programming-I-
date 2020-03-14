//��F��[�b�᭱ 
//��k(�@) 
void Create_List(Node** head, int data)
{
    if(*head==NULL){
        *head = (Node*)malloc(sizeof(Node));
        (*head)->data = data;
        (*head)->next = NULL;
    }
    else{
        Node* temp = *head;			// temp : ���F���n�ʨ� head ����m 
        while(temp->next!=NULL) temp = temp -> next;		//point
        Node* new_node = (Node*) malloc(sizeof(Node));
        temp->next = new_node;
        new_node->next = NULL;
        new_node->data = data;
    }
}
//��k(�G)
//�|�Ψ� tail
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
		(* tail)->next = newptr;		//�|�Ψ� tail �]�O���F���n�ʨ� head ����m 
		*tail = newptr;
	}
}



//��F��[�b '�e��'
void push(Node ** head,int val)
{
	Node * newptr;
	newptr = (Node *)mallon(sizeof(Node));
	
	newptr->data = val;
	newptr->next = *head;
	
	*head = newptr;
}



//�[�F��b�S�w��m 
Node * insert(Node * head, int val)
{
	Node * newptr;
	Node * pre;
	Node * current;
	newptr = (Node *)malloc(sizeof(Node));
	
	newptr->data = val;
	newptr->next = NULL;
	
	pre = NULL;
	current = head;		//�]���C�����n�q�Y�}�l�ˬd 
	
	while(current != NULL && val>current->data){
		pre = current;
		current = current->next;
	}
	
	if(pre == NULL){		//�]���i��ĤG�ӭn��i�h���F��n��b�}�Y 
		newptr->next = head;		//point
		head = newptr;
	}else{
		pre->next = newptr;
		newptr->next = current;		
	}
		
	return head;
} 





 
