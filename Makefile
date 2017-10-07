.PHONY: all clean
CC             = gcc
CPP            = g++
AR             = ar
RANLIB         = ranlib
CFLAGS         = -g -Wall -Wno-unused-function
C11FLAGS       = -g -Wall -Wno-unused-function -std=c++0x
SRCDIR         = ./src
INCLUDEDIR     = -I./include -I.
DEPS           = 
LIBS           = -lm
PROGRAM_NAME   = shell

program_C_SRCS := $(SRCDIR/ wildcard *.c)
program_C_OBJS := ${program_C_SRCS:.c=.o}
program_OBJS   := $(program_C_OBJS)



default: all
all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(program_OBJS)
	$(CC) $(CFLAGS) $(program_OBJS) -o $(PROGRAM_NAME) $(SRCDIR)/main.c

# shell: $(SRCDIR)/main.c
# 	$(CC) $(CFLAGS) -o shell $(SRCDIR)/main.c
clean:
	$(RM) $(PROGRAM_NAME)
	$(RM) $(program_OBJS)
	$(RM) *.dSYM