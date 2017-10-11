#ifndef SHELL_H_
#define SHELL_H_

#include <stdlib.h>
#include <stdio.h>

#include "logger.h"
#include "environment.h"
#include "history.h"
#include "interactive_shell.h"
#include "batch_shell.h"
#include "cd.h"

void shell_init();
void shell_close();


#endif // SHELL_H_