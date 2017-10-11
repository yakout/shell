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


int main(int argc, char *argv[], char *envp[]) { 
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


	set_variable("x", "5", 1);
	// print_all_variables();
	// printf("lookup variable = %s\n", lookup_variable("x"));
	printf("%s\n", expand_variables("$x")); 


	// shell_init();
 //    if (argc == 2) {
 //    	// batch mode;
	// 	start_shell(true);
 //    } else if (argc == 1) {
 //    	// interactive mode;
 //        start_shell(false);
 //    } else {
 //    	printf("%s\n%s\n", "** Incorrect number of command line arguments **",
 //    	 "usage: shell [BATCH_FILE_PATH]");
 //    	return 1;
 //    }
 //    shell_close();
    
    return 0;
}

