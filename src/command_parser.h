#ifndef COMMAND_PARSER_H   /* Include guard */
#define COMMAND_PARSER_H


#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "shell_util.h"

/* 
	- This function should be responsible for importing all details of the command 
	- Should specify the type of the command "comment, cd, echo, expression - X=5 -, else"
	- Should specify the arguments of the command
	- Should specify if the command is background or foreground
	- Should consider all parsing special cases, example: many spaces in  "ls     -a"

	- You're left free to decide how to return your imported details of this command

	- Best practice is to use helper function for each collection of logical instructions,
	  example: function for splitting the command by space into array of strings, ..etc
*/
command* parse_command(char* instr);



#endif // COMMAND_PARSER_H