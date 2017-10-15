#include "cd.h"

char** handle_parent_dir(const char* path) {
	char **paths = split(path, "/");
	char curr[50] = "/Users/ahmedyakout/";
	char **cur_dir_paths = split(curr, "/");
	char *new_path[10] = {NULL};

	int i = 0;
	while(*cur_dir_paths) {
		new_path[i++] = *cur_dir_paths;
		cur_dir_paths++;
	}

	while(*paths) {
		if (strcmp(*paths, "..") == 0) {
			if (i == 0) {
				 // cant go up any more
				paths++;
				continue;
			}
			new_path[--i] = NULL;
		} else {
			new_path[i++] = *paths;
		}
		paths++;
	}

	new_path[i] = NULL;
	char *full_path = malloc(sizeof(char) * i * 5);
	strcat(full_path, SEPERATOR);

	for (int j = 0; j < i ; ++j) {
		strcat(full_path, new_path[j]);
		strcat(full_path, SEPERATOR);
	}

	printf("%s\n", full_path);
	chdir(full_path);
	if (errno != 0 && errno != 10) {
		// errno=10 mean no child process which i don't what does it mean
		// and why it happens so i am ignoring it for now.
		perror("");
	} else {
		strcpy(PREV_WORKING_DIR, CURRENT_WORKING_DIR);
		strcpy(CURRENT_WORKING_DIR, full_path);
	}

	return NULL;
}



void cd(const char* path) {
	if (strstr(path, "..") != NULL) {
		handle_parent_dir(path);
		return;
	}
	if (strcmp(path, "~") == 0) {
		chdir(lookup_variable("HOME"));
		if (errno != 0 && errno != 10) {
			// errno=10 mean no child process which i don't what does it mean
			// and why it happens so i am ignoring it for now.
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
				printf("%s\n", PREV_WORKING_DIR);
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
			if (path[0] == '.') {
				strcat(full_path, CURRENT_WORKING_DIR);
				strcat(full_path, "/");
				char *temp = substring(path, 1, -1);
				strcat(full_path, temp);
			} else if (path[0] == '~') {
				strcat(full_path, lookup_variable("HOME"));
				strcat(full_path, "/");
				char *temp = substring(path, 1, -1);
				strcat(full_path, temp);
			} else {
				strcat(full_path, path);
			}
			chdir(full_path);
		}
		if (errno != 0 && errno != 10) {
			perror("");
		} else {
			strcpy(PREV_WORKING_DIR, CURRENT_WORKING_DIR);
			strcpy(CURRENT_WORKING_DIR, full_path);
		}
	}
}