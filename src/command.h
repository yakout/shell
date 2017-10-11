#ifndef COMMAND_H_
#define COMMAND_H_ 

#include <stdlib.h>

typedef struct command_t command_t;
struct command_t {
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
	/**
	 * is expression command e.g export PATH=/bin/, x=5 ...
	 */
	int expression;

	// functions headers
	char* (*get_command_name)(command_t *self);
	char** (*get_arguments)(command_t *self);
	int (*is_background_mode)(command_t *self);
};


int command_init(command_t *self, int len, int argc);

char* command_get_command_name(command_t *self);
char** command_get_arguments(command_t *self);
int command_is_background_mode(command_t *self);

int command_clean(command_t *self);


#endif // COMMAND_H_