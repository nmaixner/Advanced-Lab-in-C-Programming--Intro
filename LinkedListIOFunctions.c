#include "LinkedListIOFunctions.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


node* create_node(int value)
{
	node* new_node = (node*)malloc(sizeof(node)); 
	if (new_node != NULL) {
		new_node->data = value;
		new_node->next_node = NULL;
	}
	return new_node;
}
node* add_start(node* current_head, int value)
{
	node* new_head = create_node(value);
	new_head->next_node = current_head;
	return new_head;
}

node* add_last(node* head, int value)
{
	node* new_last = create_node(value);
	if (head == NULL)
		return new_last;
	node* temp = head;
	while (temp->next_node != NULL)
		temp = temp->next_node;
	temp->next_node = new_last;
	return head;
}

node* add_after(node* head, int new_value, int searched_value)
{
	//if the function fail will return NULL, it should be checked in main!
	
	if (head == NULL)
	{
		printf("requested value wasnt found, got empty list\n");
		return NULL;
	}

	node* temp = head;
	while (temp!= NULL) {
		if (temp->data == searched_value)
		{
			node* new_middle = create_node(new_value);
			new_middle->next_node = temp->next_node;
			temp->next_node = new_middle;
			return head;
		}
		temp = temp->next_node;
	}
	//if we are here, the searched value wasnt found!
	printf("requested value wasnt found!\n");
	free_all_list(head);
	return NULL;
}

int print_index(node* head, int value) 
{//notice- this function return only index number and not the head! 
	int curr_index = 0;
	if (head == NULL)
	{
		printf("%d", -1);
		return -1;
	}

	node* temp = head;

	while (temp != NULL) {
		if (temp->data == value)
		{
			printf("%d\n", curr_index);
			return value;
		}
		temp = temp->next_node;
		curr_index++;
	}
	//if we are here, the searched value wasnt found!
	printf("%d\n", -1);
	return -1;
}

node* delete_node(node* head, int index_to_delete)
{
	node* new_head;
	if (index_to_delete == 0) {
		new_head = head->next_node;
		free(head);
		return new_head;
	}

	node* ptr_to_node = head, *previous_ptr = NULL;
	int count_current_index = 0;

	while (count_current_index < index_to_delete) {
		previous_ptr = ptr_to_node;
		ptr_to_node = previous_ptr->next_node;
		count_current_index++;
		if (ptr_to_node == NULL) { //happen when we arrived to high index
			printf("index is too high! not in list!\n");
			free_all_list(head);
			return NULL;
		}
	}
	previous_ptr->next_node  = ptr_to_node->next_node;
	free(ptr_to_node);
	return head;
}

void print_list(node* head) 
{
	node* iteration_ptr = head;
	printf("[");
	while (iteration_ptr != NULL) {
		printf("%d", iteration_ptr->data);
		iteration_ptr = iteration_ptr->next_node;
		if (iteration_ptr != NULL) { 
			printf(", ");
		}
	}
	printf("]\n");
	return;
}

void free_all_list(node* head) 
{
	node* iteration_ptr = head, *temp_ptr = NULL;
	while (iteration_ptr != NULL) {
		temp_ptr = iteration_ptr->next_node;
		free(iteration_ptr);
		iteration_ptr = temp_ptr;
	} 
	return;
}





