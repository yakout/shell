#include "logger.h"



char *LOGS_DIR = "shell-logs";
char *EXTENSIION = ".log";
FILE* log_file;

void init_logger() {
	create_logs_dir();
	char *log_file_name = get_current_timestamp();
	char *full_path = malloc(sizeof(char) * MAX_LOG_MSG_LENGTH);
	strcat(full_path, HOME_PATH);
	strcat(full_path, SEPERATOR);
	strcat(full_path, LOGS_DIR);
	strcat(full_path, SEPERATOR);
	strncat(full_path, log_file_name, 24);
	strcat(full_path, EXTENSIION);
	log_file = fopen(full_path, "a+");
	printf("log file name = %s\n", full_path);
}

void append_to_logger(char *msg, char *level) {
	char current_timestamp[25] = "";
	strncat(current_timestamp, get_current_timestamp(), 24);
	fprintf(log_file, "[%s][%s] %s\n", level, current_timestamp ,msg);
	fflush(log_file);
}

void close_logger() {
	if (fclose(log_file) == 0) {
		// success
	} else {
		printf("%s\n", "failed to close file");
	}
}

void create_logs_dir() {
	struct stat st = {0};
	char buffer[100] = "";
	strcat(buffer, HOME_PATH);
	strcat(buffer, SEPERATOR);
	strcat(buffer, LOGS_DIR);
	if (stat(buffer, &st) == -1) {
		// if doesn't exist create new one.
    	mkdir(buffer, 0700);
    	perror("");
	}
}
