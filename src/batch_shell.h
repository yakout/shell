#ifndef BATCH_SHELL_H_
#define BATCH_SHELL_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "shell_util.h"
#include "executer.h"
#include "command.h"
#include "command_parser.h"

FILE* batch_file;

void open_commands_batch_file(char *path);

FILE* get_commands_batch_file();

void close_commands_batch_file();

void batch_mode(char *file_path);

#endif // BATCH_SHELL_H_