#include "echo.h"

void echo(char** argv) {
	while(*argv) {
		printf("%s", *argv);
		argv++;
	}
	printf("\n");
}