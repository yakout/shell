#include "shell.h"

void shell_init() {
	setup_environment();
	open_history_file();
	init_logger();
	append_to_logger("shell init completed succesfully", "DEBUG");
}

void shell_close() {
	close_history_file();
	close_logger();
}
