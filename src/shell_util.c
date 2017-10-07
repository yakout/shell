#include "shell_util.h"


char *read_line(void) {
    char *line = malloc(100), *linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stdin);
        if(c == EOF) {
            return NULL;
        }

        if(--len == 0) {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if((*line++ = c) == '\n')
            break;
    }
    *--line = '\0'; // replace the \n with string terminator
    return linep;
}

char* get_current_timestamp() {
    time_t clk = time(NULL);
    return ctime(&clk);
}


void trim(char* string)
{
    int src = 0, dest = 0;
    int len = strlen(string);

    // advance start to first nonspace character
    while(isspace(string[src])) src++;

    // shift the string
    for(; src < len; src++, dest++) {
        string[dest] = string[src];
    }

    // put all trailing spaces to '\0'
    dest = len - 1;
    while(isspace(string[dest])) {
        string[dest--] = '\0';
    }
}


char** split(char *string, const char *sep) {
    int tokens_count = 0;
    char *temp = string;

    while(*temp) {
        if (*temp == *sep) {
            tokens_count++;
        }
        temp++;
    }

    tokens_count++; // add space for last token
    tokens_count++; // add space for terminating null
    char **tokens = malloc(sizeof(char*) * tokens_count);

    int i = 0;
    char *token = strtok(string, sep);
    tokens[i++] = strdup(token);
    while(token != NULL) {
        token = strtok(NULL, sep);
        tokens[i++] = token;
    }

    return tokens;
}
