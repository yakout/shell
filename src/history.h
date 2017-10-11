#ifndef HISTORY_COMMAND_H_
#define HISTORY_COMMAND_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "shell_util.h"
#include "environment.h"

void open_history_file();

FILE* get_history_file();

void add_to_history(char* instr);

void close_history_file();

void history();

#endif // HISTORY_COMMAND_H_