#include "interactive_shell.h"


void interactive_mode() {
	printf("%s\n", "Starting interactive mode ...");

	while(1) {
		printf("%s> ", get_current_dir());
		
		char *instruction;
		instruction = read_line();
		trim(instruction);

		// printf("%s#\n", instruction);
		if (strlen(instruction) == 0) {
			continue;
		}

		if (instruction == NULL) {
			// CNTRL + D (end of input) signal or no memory available to read more lines
			printf("\n");
			break;
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
		int i = 0;
		while(cmd->arguments[i]) {
			// printf("arg[%d] = %s\n", i, cmd->arguments[i]);
			i++;
		}
		//

		/*   EXECUTION   */
		if (execute(cmd) != 0) {
			printf("%s\n", "invalid command");
			continue;
		}
	}
}