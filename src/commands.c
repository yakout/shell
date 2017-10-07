#include "commands.h"


void cd(const char* path) {
	// if path = ~ -> home
	
}


void echo( const char* message ) {
	// you should implement this function
}


void history() {
	FILE* history = get_history_file();
	fseek(history, 0, SEEK_SET);
	char line[MAX_COMMAND_LENGTH];

	while (fgets(line, MAX_COMMAND_LENGTH, history)) {
		printf("%s", line);
	}
}