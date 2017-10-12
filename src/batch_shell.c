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
	char instruction[MAX_COMMAND_LENGTH];

	while (fgets(instruction, sizeof(instruction), file)) {
        printf("%s", instruction);
        trim(instruction);

        if (strlen(instruction) == 0) {
			continue;
		}

		if (strlen(instruction) > MAX_COMMAND_LENGTH) {
			printf("%s\n", "invalid command: max size exceeded.");
			continue;
		}

		/*    COMMAND STRUCT CONSTRUCTION     */
		command_t *cmd = parse_command(instruction);
		if (cmd == NULL) {
			// exit shell
			break;
		}

		add_to_history(instruction);

		// JUST FOR DEBUGING
		// printf("cmd_name = %s\n", cmd->command_name);
		// int i = 0;
		// while(cmd->arguments[i]) {
			// printf("arg[%d] = %s\n", i, cmd->arguments[i]);
			// i++;
		// }
		//

		/*   EXECUTION   */
		if (execute(cmd) != 0) {
			printf("%s\n", "invalid command");
			continue;
		}
    }

	close_commands_batch_file();
}