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

void trim(char* str) {
    if (str == NULL) return;

    int src = 0, dest = 0;
    int len = strlen(str);

    // advance start to first nonspace character
    while(isspace(str[src])) src++;

    int new_len = len - src;
    // shift the string
    for(; src < len; src++, dest++) {
        str[dest] = str[src];
    }

    for(int i = new_len; i < len; i++) {
        str[i] = ' ';
    }

    // put all trailing spaces to '\0'
    dest = len - 1;
    while(isspace(str[dest])) {
        str[dest--] = '\0';
    }
}


char** split(char *str, const char *sep) {
    if (str == NULL) return NULL;

    int tokens_count = 0;
    char *temp = str;

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
    char *token = strtok(str, sep);
    tokens[i++] = strdup(token);
    while(token != NULL) {
        token = strtok(NULL, sep);
        tokens[i++] = token;
    }

    return tokens;
}


void substring_m(char* str, int start, int end) {
    if (str == NULL) return;

    if (end == -1) {
        end = strlen(str);
    }
    
    for (int src = start, dest = 0; dest < strlen(str); ++src, ++dest) {
        if (dest >= end - start) {
            str[dest] = '\0';
        } else {
            str[dest] = str[src];
        }
    }
}


char* substring(const char* str, int start, int end) {
    if (str == NULL) return NULL;

    char *substr = malloc(sizeof(char) * strlen(str));
     if (end == -1) {
        end = strlen(str);
    }
    
    for (int src = start, dest = 0; dest < strlen(str); ++src, ++dest) {
        if (dest >= end - start) {
            substr[dest] = '\0';
        } else {
            substr[dest] = str[src];
        }
    }
    return substr;
}


int contains(const char* str, char ch) {
    if (str == NULL) return 0;

    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == ch) {
            return 1;
        }
    }
    return 0;
}

void replace_all(char* str, char old, char new) {
    if (str == NULL) return;

    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == old) {
            str[i] = new;
        }
    }
}

void strcat_c (char *str, char ch) {
    if (str == NULL) return;

    for (; *str; str++);
    *str++ = ch; 
    *str++ = '\0'; // terminating string
}


void to_lower(char *str) {
    for (; *str; ++str) *str = tolower(*str);
}
