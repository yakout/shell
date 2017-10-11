#ifndef CHANGE_DIR_COMMAND_H_
#define CHANGE_DIR_COMMAND_H_

#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "environment.h"
#include "shell_util.h"

/**
 * @brief change current process directory
 * @details changes the current directory of the current process to the given directory.
 * 
 * @param path distenation path directory
 */
void cd(const char* path);


#endif // CHANGE_DIR_COMMAND_H_