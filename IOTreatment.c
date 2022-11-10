#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedListIOFunctions.h"
#include "IOTreatment.h"


void CommandToLowerCase(char *command_from_user, char *command_lowercase)
{
	int index = 0;
	while (command_from_user[index] != '\n') {
		command_lowercase[index] = tolower(command_from_user[index]);
		index++;
	}
	command_lowercase[index] = '\0';
	return;
}


node* ExecuteCommand(node *my_list, char *command_lowercase)
{
	char *operation;
	char *str_i, *str_j;
	operation = strtok(command_lowercase, " ");
	str_i = strtok(NULL, " ");
	str_j = strtok(NULL, " ");

	int i, j;
	if (NULL != str_i) {
		i = atoi(str_i);
	}
	if (strcmp(operation, "add_end") == 0) {
		 my_list = add_last(my_list, i);
	}
	else if (strcmp(operation, "add_start") == 0) {
		my_list = add_start(my_list, i);
	}
	else if (strcmp(operation, "add_after") == 0) {
		j = atoi(str_j);
		my_list = add_after(my_list, i, j);
		if (NULL == my_list) {
			exit(-1);
		}
	}
	else if (strcmp(operation, "index") == 0) {
		print_index(my_list, i);
	}
	else if (strcmp(operation, "del") == 0) {
		node *temp_node = my_list;
		int num_of_objects = 0;
		while (temp_node != NULL) {
			temp_node = temp_node->next_node;
			num_of_objects++;
		}
		my_list = delete_node(my_list, i);
		if ((NULL == my_list) & (num_of_objects != 1)) {
			exit(-1);
		}
	}
	else if (strcmp(operation, "print") == 0) {
		print_list(my_list);
	}
	else if (strcmp(operation, "exit") == 0) { 
		free_all_list(my_list);
		exit(-1);
	}
	else { //illegal command
		printf("illegal command\n");
	}
	return my_list;
}






