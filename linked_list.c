#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
	int data;
	struct linked_list* next;
};

struct linked_list* create_node(int data){
	struct linked_list* Node = (struct linked_list*)malloc(sizeof(struct linked_list));
	if(!Node){
	 printf("Memory allocation failed");
         exit(1);
	}
	Node->data = data;
	Node->next = NULL;
	return Node;
}

struct linked_list* add_new_element(struct linked_list* linked_list, int data)
{
	struct linked_list* Node = (struct linked_list*)malloc(sizeof(struct linked_list));
	if(!Node){
	 printf("Memory allocation failed");
	 exit(1);
	}

	Node->data = data;
	Node->next=NULL;

	if(linked_list==NULL){
		return Node;
	}

	struct linked_list* temp_node = linked_list;
	while(temp_node->next != NULL){
		temp_node=temp_node->next;
	}
	temp_node->next = Node;
	return linked_list;
}
struct linked_list* add_front_new_element(struct linked_list* linked_list, int data)
{
	struct linked_list* Node = (struct linked_list*)malloc(sizeof(struct linked_list));
	if(!Node){
	 printf("Memory allocation failed");
	 exit(1);
	}

	struct linked_list* temp_node = linked_list;
	Node->data = data;
	Node->next = NULL;

	if(linked_list==NULL){
		return Node;
	}
	Node->next=temp_node;

	return Node;
}
struct linked_list* add_at_pos_new_element(struct linked_list* linked_list, int position, int data)
{
	struct linked_list* Node = (struct linked_list*)malloc(sizeof(struct linked_list));
	struct linked_list * temp_node = linked_list;
	if(!Node){
	 printf("Memory allocation failed");
	 exit(1);
	}

	Node->data = data;
	Node->next = NULL;

	if(linked_list==NULL){
		return Node;
	}

	if(linked_list==NULL){
		printf("There is no elements in a list");
		return NULL;
	}
	
	for(int idx = 0; idx < position - 1; idx++){
		temp_node = temp_node->next;
	}

        Node->next = temp_node->next;

	temp_node->next = Node;

	return linked_list;
}
void print_all_elements(struct linked_list* lst)
{
	struct linked_list * temp = lst;
	while(temp != NULL)
	{
		printf("%d \n", temp->data);
		temp = temp->next;
	}
}

int get_size_list(struct linked_list *lst){
	int counter = 0;
	if(lst==NULL){
		printf("There is no elements in a list");
		return counter;
	}
	struct linked_list * temp = lst;
	while(temp != NULL)
	{
		counter++;
		temp = temp->next;
	}
	return counter;
}

struct linked_list* remove_last_element(struct linked_list * lst)
{
	struct linked_list * temp = lst;
	if(lst==NULL){
		printf("There is no elements in a list");
		return NULL;
	}
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next=NULL;
	return lst;
}

struct linked_list* remove_pos_element(struct linked_list * lst, int position)
{
	struct linked_list * temp = lst;
	struct linked_list * prev = NULL;

	if(lst==NULL){
		printf("There is no elements in a list");
		return NULL;
	}
	
	for(int idx = 0; idx < position; idx++){
		prev = temp;
		temp = temp->next;
	}

	prev->next = temp->next;

	free(temp);
	return lst;
}
struct linked_list* remove_value(struct linked_list * lst, int data)
{
	struct linked_list * temp = lst;
	struct linked_list * prev = NULL;

	if(lst==NULL){
		printf("There is no elements in a list");
		return NULL;
	}
	
	while(temp != NULL){
		if(temp->data == data){
		    if(prev == NULL){
		            lst=temp->next;
	                    free(temp);
			    temp = lst;
		    }
		    else{
		    	prev->next = temp->next;
			free(temp);
			temp = prev->next;
		    }
		}
		else {
			prev = temp;
			temp = temp->next;
		}
	}


	return lst;
}
struct linked_list* remove_first_element(struct linked_list * lst)
{
	struct linked_list * temp = lst;
	if(lst==NULL){
		printf("There is no elements in a list");
		return NULL;
	}
	lst=lst->next;
	free(temp);
	return lst;
}
int main()
{
	struct linked_list* ptr_lst = create_node(20);
	ptr_lst = add_new_element(ptr_lst, 100);
	ptr_lst = add_new_element(ptr_lst, 45);

	ptr_lst = add_new_element(ptr_lst, 75);
	struct linked_list* temp_ptr = ptr_lst;
	while(temp_ptr != NULL)
	{
		printf("%d \n", temp_ptr->data);
		temp_ptr = temp_ptr->next;
	}
	int size = get_size_list(ptr_lst);
	printf("elements in a list are %d \n", size);
	print_all_elements(ptr_lst);
	printf("remove last element \n");
	ptr_lst= remove_last_element(ptr_lst);
	print_all_elements(ptr_lst);
	printf("remove first element \n");
	ptr_lst = remove_first_element(ptr_lst);
	ptr_lst = remove_pos_element(ptr_lst, 1);
	print_all_elements(ptr_lst);
	printf("Ad new element at front \n");
	ptr_lst = add_front_new_element(ptr_lst, 1000);
	print_all_elements(ptr_lst);
	ptr_lst = add_at_pos_new_element(ptr_lst, 1, 1000);
	print_all_elements(ptr_lst);
	printf("Add new element \n");
	ptr_lst = add_at_pos_new_element(ptr_lst, 1, 1000);
	print_all_elements(ptr_lst);
	printf("Remove element \n");
	ptr_lst = remove_value(ptr_lst, 1000);
	print_all_elements(ptr_lst);
return 0;
}
