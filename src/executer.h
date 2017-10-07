#ifndef EXECUTER_H_   /* Include guard */
#define EXECUTER_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "command.h"
#include "shell_util.h"
#include "environment.h"

int execute(command *cmd);

#endif // EXECUTER_H_