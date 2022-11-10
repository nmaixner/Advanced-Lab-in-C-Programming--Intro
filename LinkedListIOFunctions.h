#ifndef LINKED_LIST_FUNCTIONS
#define LINKED_LIST_FUNCTIONS

//typedef struct node* node; //Define node as pointer of data type struct LinkedList
typedef struct node {
	// node contain its value and pointer to next node
	int data;
	struct node* next_node;
}node;

node* add_start(node* current_head, int value);
node* add_last(node* head, int value);
node* add_after(node* head, int new_value, int searched_value);
int print_index(node* head, int value);
node* delete_node(node* head, int index_to_delete);
void print_list(node* head);
void free_all_list(node* head);


#endif

