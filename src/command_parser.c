#include "command_parser.h"


char* expand_variables(char* string) {
	char *buffer = malloc(sizeof(char) * 255);
	const char *current_variable;
	int end = 0, start = 0;
	int write_flag = 0; // write flag to buffer 
	for (int i = 1, start = i; i <= strlen(string); ++i) {
		// printf("string[i]=%c\n", string[i]);
		if (string[i] == '$' || (!isalpha(string[i]) && !isdigit(string[i]))) {
			if (!write_flag) {
				end = i;
				// printf("string=%s\n", string);
				// printf("start=%d\n", start);
				// printf("end+1=%d\n", end);
				// printf("substring=%s\n", substring(string, start, end));
				current_variable = lookup_variable(substring(string, start, end));
				// printf("current_variable=%s\n", current_variable);
				if (current_variable != NULL) {
					strcat(buffer, current_variable);
				} else {
					// var not found
					// strcat(buffer, "");
				}
				start = i + 2;
			}
			if (string[i] != '$') {
				write_flag = 1;
				strcat_c(buffer, string[i]);
			} else {
				write_flag = 0;
				start = i + 1;
			}
		} else if (write_flag) {
			strcat_c(buffer, string[i]);
		}
	}
	// printf("buffer=%s\n", buffer);
	return buffer;
}

command_t* parse_command(char* instr) {
	// extracted info:
	/**
		1- background or foreground (& at the end of the command)
		2- list of arguments ["-a", "-l", NULL]
		3- command name
	*/

	// parse
	// handle export expression
	// handle regular expression
	// handle regular command

	int background_mode = 0;
	if (instr[strlen(instr) - 1] == '&') {
		background_mode = 1;
		instr[strlen(instr) - 1] = '\0';
	}

	// split the command
	char **argv = malloc(strlen(instr) * sizeof(char *));
	int argc = 0;
	char* pch = strtok(instr, " \n\t");
	// add to args list
	if (contains(pch, '$')) {
		argv[argc++] = expand_variables(pch);
	} else {
		argv[argc++] = pch;
	}
	// fill the args list
	while (pch != NULL) {
		// printf("pch=%s\n", pch);
		pch = strtok(NULL, " \n\t");
		if (contains(pch, '$')) {
			argv[argc++] = expand_variables(pch);
		} else {
			argv[argc++] = pch;
		}
	}
	// now we have the command splitted 



	// CHECK SPECIAL COMMANDS
	int expression = 0;
	if (contains(argv[0], '=')) {
		// x=5
		char **arr = split(instr, "=");	
		if(arr[1] == NULL) {
			// x=
			set_variable(arr[0], "", 1);	
			printf("session variable is set: %s=%s\n", arr[0], "");
		} else {
			// key=value
			set_variable(arr[0], arr[1], 1);
			printf("session variable is set: %s=%s\n", arr[0], arr[1]);
		}
		expression = 1;
	} else if (strcmp(argv[0], "exit") == 0) {
		printf("%s\n", "exiting shell ... done");
		return NULL;
	} else if (strcmp(argv[0], "export") == 0) {
		char **arr;
		if ((arr = split(argv[1], "=")) != NULL) {
			if(arr[1] == NULL) {
				// x=
				set_variable(arr[0], "", 1);
				printf("environment variable is set: %s=%s\n", arr[0], "");
			} else {
				// key=value
				set_variable(arr[0], arr[1], 1);
				printf("environment variable is set: %s=%s\n", arr[0], arr[1]);
			}
		}
		expression = 1;
	}


	// allocate memory for command_t and fill the attributes
  	int command_path_len = 5 + strlen(argv[0]) + 1; // /bin/ + command + '\0'
	command_t* cmd = malloc(sizeof(command_t) + sizeof(char *) * argc + sizeof(char) * command_path_len);
	command_init(cmd, command_path_len, argc);

	// fill resutls into cmd
	cmd->command_name = argv[0];

	for (int i = 0; i < argc; ++i) {
		cmd->arguments[i] = argv[i];
	}

	cmd->background = background_mode;
	cmd->expression = expression;

	return cmd;
}
