#include "history.h"

static char *HISTORY_FILE_NAME = "shell-history.txt";
static FILE* history_file;

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
	fflush(history_file);
}

void close_history_file() {
	if (fclose(history_file) == 0) {
		// file closed successfully
	} else {
		// failed to close
	}
}

void history() {
	FILE* history = get_history_file();
	fseek(history, 0, SEEK_SET);
	char line[MAX_COMMAND_LENGTH];

	while (fgets(line, MAX_COMMAND_LENGTH, history)) {
		printf("%s", line);
	}
}
