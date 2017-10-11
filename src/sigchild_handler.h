#ifndef SIGCHILD_HANDLER_H_
#define SIGCHILD_HANDLER_H_

#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "logger.h"


void sigchld_handler(int sig);

#endif // SIGCHILD_HANDLER_H_