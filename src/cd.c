#include "cd.h"

void cd(const char* path) {
	if (strcmp(path, "~") == 0) {
		chdir(lookup_variable("HOME"));
		if (errno != 0 && errno != 10) {
			perror("");
		} else {
			strcpy(PREV_WORKING_DIR, CURRENT_WORKING_DIR);
			strcpy(CURRENT_WORKING_DIR, lookup_variable("HOME"));
		}
	} else if (strcmp(path, "-") == 0) {
		if (strcmp(CURRENT_WORKING_DIR, PREV_WORKING_DIR) == 0) {
			printf("%s\n", "cd: OLDPWD not set");
		} else {
			char temp[255] = "";
			chdir(PREV_WORKING_DIR);
			if (errno != 0 && errno != 10) {
				perror("");
			} else {
				strcpy(temp, PREV_WORKING_DIR);
				strcpy(PREV_WORKING_DIR, CURRENT_WORKING_DIR);	
				strcpy(CURRENT_WORKING_DIR, temp);
			}
		}
	} else {
		char full_path[255] = "";
		if (path[0] == '/') {
			chdir(path);
			strcpy(full_path, path);
		} else {
			strcat(full_path, CURRENT_WORKING_DIR);
			strcat(full_path, "/");
			if (path[0] == '.') {
				char *temp = substring(path, 1, -1);
				strcat(full_path, temp);
			} else {
				strcat(full_path, path);
			}
			chdir(full_path);
		}
		if (errno != 0 && errno != 10) {
			printf("#%d#\n", errno);
			perror("");
		} else {
			strcpy(PREV_WORKING_DIR, CURRENT_WORKING_DIR);
			strcpy(CURRENT_WORKING_DIR, full_path);
		}
	}
}