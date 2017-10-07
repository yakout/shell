#include "variables.h"

extern char **environ;

#define MAX_KEYS_SIZE 100

char *keys[MAX_KEYS_SIZE];
int keys_count = 0;

const char* lookup_variable( const char* key ) {
	return getenv(key);
}

void set_variable(const char* key, const char* value, int replace) {
  keys[keys_count++] = key;
	int status = setenv(key, value, replace);
  if (status == 0) {
    // success
  } else {
    // failed
    // check global variable errno which indicates the error
  }
}

void print_all_variables( void ) {
  // implementation #1 using "char *envp[]"
  // char** env;
 //   for (env = envp; *env != 0; env++) {
 //     char* thisEnv = *env;
 //     printf("%s\n", thisEnv);    
 //   }


    // implementation #2 using environ
    //  int i = 1;
    //  char *s = *environ;
    //  for (; s; i++) {
    //      printf("%s\n", s);
    //      s = *(environ+i);
    // }

  for (int i = 0; i < keys_count; ++i) {
    printf("%s\n", lookup_variable(keys[i]));
  }
}