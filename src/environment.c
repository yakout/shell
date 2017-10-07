#include "environment.h"


void setup_environment() {
	/* SET HOME PATH */
	if ((HOME_PATH = getenv("HOME")) == NULL) {
    	HOME_PATH = getpwuid(getuid())->pw_dir;
	}

	/* SET CURRENT DIRECTORY */
	CURRENT_WORKING_DIR = malloc(100);
	if (getcwd(CURRENT_WORKING_DIR, 100) != NULL) {
       fprintf(stdout, "Current working dir: %s\n", CURRENT_WORKING_DIR);
	} else {
       perror("getcwd() error");
	}

	/* SET CURRENT DIRECTORY */
	ENVIRONMENT_PATHS = split(getenv("PATH"), ":");
}



char **get_environment_paths() {
	return ENVIRONMENT_PATHS;
}