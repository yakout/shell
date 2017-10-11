#ifndef SHELL_UTIL_H_
#define SHELL_UTIL_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 512
#define SEPERATOR "/" // UNIX SEPERATOR, NOT PORTABLE!

/**
 * @brief read line from stdin
 * @details read line from stdin, the line ends when user enters \n and terminated by '\0'
 * @return return the line read from user without including the \n 
 */
char* read_line();
/**
 * @brief get current timestamp
 * @details get the current timestamp in readable form.
 * @return return string ending with '\n\0'
 */
char* get_current_timestamp();
/**
 * @brief trim the string
 * @details trim the leading and trailing spaces from string given string
 * 
 * @param str original string to trim.
 */
void trim(char* str);
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param str [description]
 * @param sep [description]
 * 
 * @return [description]
 */
char** split(char* str, const char* sep);
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param str [description]
 * @param start [description]
 * @param end [description]
 */
void substring_m(char* str, int start, int end);
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param str [description]
 * @param start [description]
 * @param end [description]
 * @return [description]
 */
char* substring(const char* str, int start, int end);
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param str [description]
 * @param start [description]
 * @param end [description]
 * @return [description]
 */
int contains(const char* str, char ch);
/**
 * @brief replace specific character in str.
 * @details [long description]
 * 
 * @param str [description]
 * @return [description]
 */
void replace_all(char* str, char old, char new);
/**
 * @brief append character to string
 * @details [long description]
 * 
 * @param str [description]
 * @param c [description]
 */
void strcat_c(char *str, char ch);


#endif // SHELL_UTIL_H_