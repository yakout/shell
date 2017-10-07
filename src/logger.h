#ifndef LOGGER_H_
#define LOGGER_H_ 

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#include "environment.h"
#include "shell_util.h"


#define MAX_LOG_MSG_LENGTH 255

/**
 * @brief [creates new log file for the current session]
 * @details [long description]
 */
void init_logger();
/**
 * @brief [adds new log msg to current session log file]
 * @details [long description]
 */
void append_to_logger(char *msg, char *level);
/**
 * @brief [closes the logger]
 * @details [long description]
 */
void close_logger();
/**
 * @brief [creates the folder /shell-logs/ under home directory if doesn't exist]
 * @details [long description]
 */
void create_logs_dir();



#endif // LOGGER_H_