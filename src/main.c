#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include "shell.h"
#include "shell_util.h"
#include "logger.h"
#include "command_parser.h"
#include "variables.h"
#include "cd.h"


/**
 * ASSUMPTIONS:
 * - echo " will print " and will not print \n and wait for another "
 * 
 * 
 */

int main(int argc, char *argv[], char *envp[]) { 
	// char curr[20] = "../../dir/../";
	// char **cur_dir_paths = split(curr, "/");	
	// while(*cur_dir_paths) {
	// 	printf("%s\n", *cur_dir_paths);
	// 	cur_dir_paths++;
	// }

	// char path[100] = "../../../../../main/";
	// if (strstr(path, "..") != NULL) {
	// 	handle_parent_dir(path);
	// 	return 0;
	// }

	// TEST CODE 
	// assert(1==2);
	// char str[] = "ls -a -l";
	// char* pch = strtok(str, " \n\t");

	// while (pch != NULL) {
	// 	printf ("%s\n", pch);
	// 	pch = strtok(NULL, " ");
  	// }

	// char *line = read_line();
	// if (line[4] == '\n') {
	// 	printf("%s\n", "yes");
	// } else {
	// 	printf("%s\n", "no");
	// }
	// printf("%d\n", strcmp(line, "exit"));
	// print_all_variables();
	// echo("");
	// cd("");
	// printf("%s\n", "hi");
	// printf("PATH : %s\n", getenv("PATH"));
	// printf("HOME : %s\n", getenv("HOME"));
	// printf("ROOT : %s\n", getenv("ROOT"));
	// setenv("test", "hi", 0); // 0 to not overwrite existing variable
	// printf("test : %s\n", getenv("test"));


	// printf("lookup variable = #%s#\n", lookup_variable("HOME"));
	// set_variable("HOME", "", 1);
	// set_variable("y1", "j", 1);
	// set_variable("x", "3", 1);
	// print_all_variables();
	// printf("lookup variable = #%s#\n", lookup_variable("HOME"));
	// printf("%s\n", expand_variables("$x/$y/$y1/$HOME/end/$x/$x/ end/\"$y1\"/. "));

	// char ch[5] = "\"$x\"";
	// replace_all(ch, '\"', ' ');
	// trim(ch);
	// printf("%s\n", ch);


	// char buf[100] = "  						                   echo 1 + 2       2                  ";
	// trim(buf);
	// printf("%s\n", buf);
	// printf("%d\n", strlen(buf));

	shell_init();
    if (argc == 2) {
    	// batch mode;
		batch_mode(argv[1]);
    } else if (argc == 1) {
    	// interactive mode;
        interactive_mode();
    } else {
    	printf("%s\n%s\n", "** Incorrect number of command line arguments **",
    	 "usage: shell [BATCH_FILE_PATH]");
    	return 1;
    }
    shell_close();
    return 0;
}

