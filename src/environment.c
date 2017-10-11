#include "environment.h"


void setup_environment() {
	/* SET HOME PATH */
	HOME_PATH = malloc(sizeof(char) * 255);
	if ((HOME_PATH = getenv("HOME")) == NULL) {
    	HOME_PATH = getpwuid(getuid())->pw_dir;
	}

	/* SET CURRENT AND PREV WORKING DIRECTORY */
	chdir(HOME_PATH);
	CURRENT_WORKING_DIR = malloc(sizeof(char) * 255);
	PREV_WORKING_DIR = malloc(sizeof(char) * 255);
	strcpy(CURRENT_WORKING_DIR, HOME_PATH);
	strcpy(PREV_WORKING_DIR, HOME_PATH);
	// if (getcwd(CURRENT_WORKING_DIR, 255) != NULL) {
 //       fprintf(stdout, "Current working dir: %s\n", CURRENT_WORKING_DIR);
       // strcpy(PREV_WORKING_DIR, CURRENT_WORKING_DIR);
	// } else {
 //       perror("getcwd() error");
	// }

	/* SET PATHS */
	ENVIRONMENT_PATHS = split(getenv("PATH"), ":");
}



char **get_environment_paths() {
	return ENVIRONMENT_PATHS;
}