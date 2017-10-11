#include "sigchild_handler.h"

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