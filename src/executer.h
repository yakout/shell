#ifndef EXECUTER_H_   /* Include guard */
#define EXECUTER_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

#include "command.h"
#include "shell_util.h"
#include "environment.h"
#include "cd.h"
#include "echo.h"
#include "history.h"
#include "sigchild_handler.h"

int execute(command_t *cmd);

#endif // EXECUTER_H_