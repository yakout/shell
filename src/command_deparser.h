#ifndef COMMAND_DEPARSER_H_
#define COMMAND_DEPARSER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "shell_util.h"
#include "command.h"
#include "shell_util.h"
#include "variables.h"

static char COMMAND_DEPARSER_BUFFER[MAX_COMMAND_LENGTH];

static char** argument_list[MAX_COMMAND_LENGTH];
static char* command_name[MAX_COMMAND_LENGTH];
static char** path[MAX_COMMAND_LENGTH];
static int background;


void deparse_argument(char *arg);
void deparse_command_name(char *name);
void deparse_path(char *path);
void deparse_variable(char *variable);
void reset_command_deparser();

command_t* get_deparsed_command();


#endif // COMMAND_DEPARSER_H_