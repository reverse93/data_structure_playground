#include <stdio.h>

typedef struct Node{
	int data;
        struct Node * next;
	struct Node * prev;
} Node;

void create_head(Node ** head, int data){
	(*head)->data=data;
	(*head)->next=NULL;
	(*head)->prev=NULL;
}

void add_element_to_list(Node ** head, int data)
{
	Node * node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev=NULL;

	Node *temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = node;
	node->prev = temp;
}

void add_element_begin(Node ** head, int data)
{
	Node * node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = *head;
	node->prev=NULL;
	if(*head!=NULL){
		(*head)->prev = node;
	}

	*head=node;
}

void print_all_elements(Node ** head){
	Node *temp = *head;
	while(temp != NULL){
		printf("%d \n", temp->data);
		temp = temp->next;
	}
}
void reverse_list_print(Node **head){
	Node *temp = *head;
	while(temp->next !=NULL){
		temp = temp->next;
	}
	Node *rev_temp = temp;
	while(rev_temp != NULL){
		printf("%d \n", rev_temp->data);
		rev_temp = rev_temp->prev;
	}
}

void remove_element_position(Node ** head, int position)
{
	Node * old_list = NULL;
	Node *temp_list = *head;

	for(int idx =0; idx < position; idx++)
	{
		old_list = temp_list;
		temp_list = temp_list->next;
	}

	old_list->next = temp_list->next;
        temp_list->next->prev = old_list;
	free(temp_list);
}

void remove_element_at_end(Node ** head)
{
	Node *temp_list = *head;

	while(temp_list->next->next != NULL)
	{
		temp_list = temp_list->next;
	}
        
	free(temp_list->next);
	temp_list->next = NULL;
}

void remove_element_by_value(Node ** head, int value)
{
	Node *temp_list = *head;
	Node * prev = NULL;

	if(*head == NULL){
		printf("There is no elements in linkedi list ! \n");
		return;
	}

	while(temp_list != NULL)
	{
		if(temp_list->data==value){
			printf("temp->list->data %d \n", temp_list->data);
			if(prev==NULL){
			    *head=temp_list->next;
			    free(temp_list);
			    temp_list = *head;
			}
			else{
				prev->next = temp_list->next;
				temp_list->next->prev = prev->next;
				free(temp_list);
				temp_list = prev->next;
			}
		}
		else{
			prev= temp_list;
			temp_list = temp_list->next;
		}
	}
        
}

void reverse_list(Node ** head)
{
	if(*head ==NULL || (*head)->next == NULL) return;
	Node * temp_node = *head;
	Node * prevNode = NULL;
        Node * currNode = temp_node;

	while(currNode != NULL){
		prevNode = currNode->prev;
		currNode->prev = currNode->next;
		currNode->next = prevNode;

		currNode = currNode->prev;
	}
	if(prevNode != NULL){
	  *head = prevNode->prev;
	}
}

int main(){
	Node * data = (Node*)malloc(sizeof(Node));
	create_head(&data, 10);
	add_element_to_list(&data, 99);
	add_element_begin(&data, 34); 
	add_element_begin(&data, 34); 
	add_element_begin(&data, 34); 
	add_element_begin(&data, 34); 
	print_all_elements(&data);
	printf("print reverse elements \n");
	reverse_list_print(&data);
	reverse_list(&data);
	printf("print once again \n");
	print_all_elements(&data);
	remove_element_position(&data, 1);
	print_all_elements(&data);
	printf("remove eleemnt at the end\n");
	remove_element_at_end(&data);
	print_all_elements(&data);
	printf("remove eleemnt at the end\n");
	remove_element_at_end(&data);
	print_all_elements(&data);
        remove_element_by_value(&data, 99);
	print_all_elements(&data);
	return 0;
}
