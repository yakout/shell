#include "executer.h"


void sigchld_handler(int sig) {
	// sig is the SIGCHILD
  	int status;
    pid_t child_pid;
    while ((child_pid = waitpid(-1, &status, WNOHANG)) > 0) {
    	char buffer[255] = "";
    	strcat(buffer, "Child Process terminated successfully pid=");
    	char pid_number[10];
		sprintf(pid_number, "%d", child_pid); 
		strcat(buffer, pid_number);
        append_to_logger(buffer, "DEBUG");
    }
}

int execute(command *cmd) {
	// if (foreground) -> wait until the process finished before proceeding to next command and display the prompt
	// else just display the propmpt and proceed to the next command
	pid_t pid;

	signal(SIGCHLD, sigchld_handler);
	pid = fork();
	if (pid == 0) {
		// child process

		/* SERACH PATHS FOR COMMAND AND EXECUTE */
		char** paths = get_environment_paths();
		while(*paths) {
			char full_path[MAX_COMMAND_LENGTH] = "";
			strcat(full_path, *paths);
			strcat(full_path, SEPERATOR);
			strcat(full_path, cmd->command_name);
			execv(full_path, cmd->get_arguments(cmd));
			paths++;
		}
		perror("");
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		printf("%s\n", "procees failed to create");
		exit(EXIT_FAILURE);
	} else {
		int status;
		pid_t child_pid;
		if (!cmd->is_background_mode(cmd)) {
			while ((child_pid = waitpid(pid, &status, 0)) > 0);
		}

		// parent process

		// check if any child process has finished
		// int status;
		// pid_t ch_pid = waitpid(-1, &status, WNOHANG);
		// if (cmd->is_background_mode(cmd)) {
		// 	if (ch_pid > 0) {
		// 		// child process terminated successfully
		// 		append_to_logger("Child Process terminated successfully" , "DEBUG");
		// 	} else {
		// 		// child prcess terminated with error
		// 		append_to_logger("Child Process terminated with error" , "DEBUG");
		// 	}
		// 	return status;
		// } else {
		return 0;
		// }
	}
}

