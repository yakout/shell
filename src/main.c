#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include "environment.h"
#include "commands.h"
#include "variables.h"
#include "command_parser.h"
#include "file_processing.h"
#include "executer.h"
#include "shell_util.h"
#include "logger.h"

typedef enum{false = 0 ,true = 1} bool;

void start_shell(bool read_from_file);
void batch_mode();
void shell_init();
void interactive_mode();
void test_code();
void shell_close();


int main(int argc, char *argv[], char *envp[])
{
	// test_code();

	shell_init();

    if (argc == 2) {
    	// batch mode
    	open_commands_batch_file(argv[1]);

    	if (errno != 0) {
    		char *msg = strerror(errno);
    		printf("%s\n", msg);
    		return 1;
    	} else {
			start_shell(true);
    	}
    } else if (argc == 1) {
    	// interactive mode
        start_shell(false);
    } else {
    	printf("%s\n%s\n", "** Incorrect number of command line arguments **",
    	 "usage: shell [BATCH_FILE_PATH]");
    	return 1;
    }

    shell_close();

    return 0;
}

void test_code() {
	// assert(1==2);
	// char str[] = "ls -a -l";
	// char* pch = strtok(str, " \n\t");

	// while (pch != NULL) {
	// 	printf ("%s\n", pch);
	// 	pch = strtok(NULL, " ");
 //  	}

	// char *line = read_line();
	// if (line[4] == '\n') {
	// 	printf("%s\n", "yes");
	// } else {
	// 	printf("%s\n", "no");
	// }
	// printf("%d\n", strcmp(line, "exit"));
	// print_all_variables();
	// echo("");
	// cd("");
	// printf("%s\n", "hi");
	// printf("PATH : %s\n", getenv("PATH"));
	// printf("HOME : %s\n", getenv("HOME"));
	// printf("ROOT : %s\n", getenv("ROOT"));
	// setenv("test", "hi", 0); // 0 to not overwrite existing variable
	// printf("test : %s\n", getenv("test"));
}


void shell_init() {
	setup_environment();
	open_history_file();
	init_logger();
	append_to_logger("shell init completed succesfully", "DEBUG");
}

void start_shell(bool read_from_file) {
	cd("");

	if(read_from_file){
		batch_mode();
	} else{
		interactive_mode();
	}
}

void shell_close() {
	close_history_file();
	close_logger();
}


void batch_mode() {
	FILE *file = get_commands_batch_file();
	char line[MAX_COMMAND_LENGTH];

	while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

	close_commands_batch_file();
}

void interactive_mode() {
	printf("%s\n", "Starting interactive mode ...");
	int c = 0; // TODO
	while(true) {
		c++; // TODO
		// TODO
		if (c == 100) return; // TODO
		printf("%s", "shell> ");
		char *instruction;


		instruction = read_line();
		if (instruction == NULL) {
			// CNTRL + D (end of input) signal or no memory available to read more lines
			printf("\n");
			break;
		}
		trim(instruction);
		if (strcmp(instruction, "exit") == 0) {
			printf("%s\n", "exiting shell ... done");
			return;
		} else if (*instruction == '\0') {
			continue;
		}

		add_to_history(instruction);


		/*    COMMAND STRUCT CONSTRUCTION     */

		command *cmd = parse_command(instruction);
		if (cmd == NULL) {
			printf("%s\n", "invalid command: max size exceeded.");
			continue;
		}

		printf("cmd_name = %s\n", cmd->command_name);
		int i = 0;
		while(cmd->arguments[i]) {
			printf("arg[%d] = %s\n", i, cmd->arguments[i]);
			i++;
		}


		/*   EXECUTION   */

		// special commands
		if (strcmp(cmd->command_name, "history") == 0) {
			history();
			continue;
		} else if (strcmp(cmd->command_name, "cd") == 0) {
			cd("");
			continue;
		} else if (strcmp(cmd->command_name, "echo") == 0) {
			echo("");
			continue;
		}

		// regular commands
		if (execute(cmd) != 0) {
			printf("%s\n", "invalid command");
			continue;
		}
	}
}
