#ifndef COMMAND_H_
#define COMMAND_H_ 

#include <stdlib.h>

typedef struct command command;
struct command
{
	// fields headers
	/**
	 * The command name: ls, cd, cat ..
	 */
	char* command_name;
	/**
	 * The command arguments: -a, -l, --help ..
	 */
	char** arguments;
	/**
	 * background mode (& exist or not)
	 */
	int background;

	// functions headers
	char* (*get_command_name)(command *self);
	char** (*get_arguments)(command *self);
	int (*is_background_mode)(command *self);
};


int command_init(command *self, int len, int argc);

char* command_get_command_name(command *self);
char** command_get_arguments(command *self);
int command_is_background_mode(command *self);

int command_clean(command *self);


#endif // COMMAND_H_