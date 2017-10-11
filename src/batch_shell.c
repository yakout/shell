#include "batch_shell.h"

void open_commands_batch_file(char *path) {
	printf("batch file path = %s\n", path);
	batch_file = fopen(path, "r");
}

FILE* get_commands_batch_file() {
	return batch_file;
}

void close_commands_batch_file() {
	fclose(batch_file);
}

void batch_mode(char *file_path) {
    open_commands_batch_file(file_path);

	if (errno != 0) {
		char *msg = strerror(errno);
		printf("%s, batch file not found.\n", msg);
		exit(1);
	}

	FILE *file = get_commands_batch_file();
	char line[MAX_COMMAND_LENGTH];

	while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

	close_commands_batch_file();
}