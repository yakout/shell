#ifndef FILE_PROCESSING_H_   /* Include guard */
#define FILE_PROCESSING_H_

#include <stdio.h>
#include <string.h>

#include "shell_util.h"
#include "environment.h"

void open_history_file();
FILE* get_history_file();
void add_to_history( char* );
void close_history_file();

void open_commands_batch_file();
FILE* get_commands_batch_file();
void close_commands_batch_file();


#endif // FILE_PROCESSING_H_