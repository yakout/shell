#include "echo.h"


// int check_quotes(char* str) {
// 	int dq_lock = 0; // double quotes
// 	while(*str) {
// 		if (*str == '\"') {
// 			dq_lock = !dq_lock;
// 		}
// 	}
// 	return !dq_lock;
// }

void echo(char** argv) {
	argv++; // ignore the the command name 'echo'

	while(*argv) {
		// printf("%s\n", *argv);
		replace_all(*argv, '\"', ' ');
		trim(*argv);
		if (strcmp(*argv, "~") == 0) {
			printf("%s ", lookup_variable("HOME"));
		} else {
			printf("%s ", *argv);
		}
		argv++;
	}

	printf("\n");
}