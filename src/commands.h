#ifndef COMMANDS_H_   /* Include guard */
#define COMMANDS_H_

#include <stdio.h>

#include "file_processing.h"
#include "shell_util.h"


/* 
	- This function should be responsible for implementing the "cd" shell command
*/
void cd( const char* path );  

/* 
	- This function should be responsible for implementing the "echo" shell command
	- Typically should lookup any variable included in the message
*/
void echo( const char* message );  

/**
 * @brief history command
 * @details shows history of all commands in current session.
 */
void history();


#endif // COMMANDS_H_