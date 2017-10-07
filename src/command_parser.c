#include "command_parser.h"


// int handle_variable(char* instr) {
// 	if ()
// 	char* pch = strtok(instr, "=");
// 	char* name = pch;
// 	argv[argc++] = pch;
// 	while (pch != NULL) {
// 		pch = strtok(NULL, " \n\t");
// 		argv[argc++] = pch;
//   	}	
// }

command* parse_command(char* instr) {
	// extracted info:
	/**
		1- background or foreground (& at the end of the command)
		2- list of arguments ["-a", "-l", NULL]
		3- command name
	*/

	// parse
	// if (handle_variable(instr) == 0) {
	// 	return;
	// } 
	int background_mode = 0;
	if (instr[strlen(instr) - 1] == '&') {
		background_mode = 1;
		instr[strlen(instr) - 1] = '\0';
	}

	if (strlen(instr) > MAX_COMMAND_LENGTH) {
		return NULL;
	}
	char **argv = malloc(strlen(instr) * sizeof(char *));
	int argc = 0;

	char* pch = strtok(instr, " \n\t");
	char* name = pch;
	argv[argc++] = pch;
	while (pch != NULL) {
		pch = strtok(NULL, " \n\t");
		argv[argc++] = pch;
  	}

  	int command_path_len = 5 + strlen(name) + 1; // /bin/ + command + '\0'
	command* cmd = malloc(sizeof(command) + sizeof(char *) * argc + sizeof(char) * command_path_len);
	command_init(cmd, command_path_len, argc);

	// fill resutls into cmd
	cmd->command_name = name;

	for (int i = 0; i < argc; ++i)
	{
		cmd->arguments[i] = argv[i];
	}

	cmd->background = background_mode;

	return cmd;
}

