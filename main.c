#include <stdio.h>

#include "LinkedListIOFunctions.h"
#include "IOTreatment.h"

#define COMMAND_MAX_SIZE 100
#define TRUE 1

int main()
{
	node *my_list = NULL;
	char command_from_user[COMMAND_MAX_SIZE];
	char command_lowercase[COMMAND_MAX_SIZE];
	while (TRUE) {
		fgets(command_from_user, sizeof(command_from_user), stdin);
		CommandToLowerCase(command_from_user, command_lowercase);
		my_list = ExecuteCommand(my_list, command_lowercase);
	}
	return 0;
}
