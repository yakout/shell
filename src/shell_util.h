#ifndef SHELL_UTIL_H_
#define SHELL_UTIL_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 512
#define SEPERATOR "/"

char* read_line();
char* get_current_timestamp();
void trim(char* string);
char** split(char* string, const char* sep);


#endif // SHELL_UTIL_H_