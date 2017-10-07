#include "file_processing.h"

/* 
	history file section
*/

char *HISTORY_FILE_NAME = "shell-history.txt";
FILE* history_file;

void open_history_file() {
	char full_path[50] = "";
	strcat(full_path, HOME_PATH);
	strcat(full_path, SEPERATOR);
	strcat(full_path, HISTORY_FILE_NAME);
	history_file = fopen(full_path, "w+");
}

FILE* get_history_file() {
	return history_file;
}

void add_to_history(char* instr) {
	fprintf(history_file, "%s\n", instr);
}

void close_history_file() {
	if (fclose(history_file) == 0) {
		// file closed successfully
	} else {
		// failed to close
	}
}


/* 
	CommandsBatch file section
*/
FILE* batch_file;

void open_commands_batch_file(char *path) {
	batch_file = fopen(path, "r");
}

FILE* get_commands_batch_file() {
	return batch_file;
}

void close_commands_batch_file() {
	fclose(batch_file);
}