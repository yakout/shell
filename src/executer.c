#include "executer.h"

int execute(command_t *cmd) {
	// if (foreground) -> wait until the process finished before proceeding to next command and display the prompt
	// else just display the propmpt and proceed to the next command

	// handling special commands in parent process
	to_lower(cmd->command_name);
	if (strcmp(cmd->command_name, "history") == 0) {
		history();
		return 0;
	} else if (strcmp(cmd->command_name, "cd") == 0) {
		if (cmd->get_arguments(cmd)[1] == NULL) {
			cd("~");
		} else {
			cd(cmd->get_arguments(cmd)[1]);
		}
		return 0;
	} else if (strcmp(cmd->command_name, "echo") == 0) {
		echo(cmd->get_arguments(cmd));
		return 0;
	} else if (cmd->expression) {
		return 0;
	}

	/* SIGNAL HANDLERS */
	signal(SIGCHLD, sigchld_handler);

	/* PROCESS CREATION */
	pid_t pid;
	pid = fork();
	if (pid == 0) {
		// child process
		/* SERACH PATHS FOR COMMAND AND EXECUTE */
		char** paths = get_environment_paths();
		// sleep(2);
		if (cmd->command_name[0] == '/') {
			// if the user provides the path for the command.
			execv(cmd->command_name, cmd->get_arguments(cmd));
		} else {
			// search for command path.
			while(*paths) {
				char full_path[MAX_COMMAND_LENGTH] = "";
				strcat(full_path, *paths);
				strcat(full_path, SEPERATOR);
				strcat(full_path, cmd->command_name);
				execv(full_path, cmd->get_arguments(cmd));
				paths++;
			}
		}
		perror("");
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		printf("%s\n", "procees failed to create");
		exit(EXIT_FAILURE);
	} else {
		// parent process
		int status;
		if (!cmd->is_background_mode(cmd)) {
			pid_t child_pid;
			while ((child_pid = waitpid(-1, &status, WUNTRACED)) > 0);
		}
		return 0;
	}
}

