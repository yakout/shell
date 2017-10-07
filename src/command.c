#include "command.h"


int command_init(command *self, int len, int argc)
{
    self->command_name = malloc(sizeof(char *) * len);
    self->arguments = malloc(sizeof(char *) * argc);
    self->background = 0;
    self->get_command_name = command_get_command_name;
    self->get_arguments = command_get_arguments;
    self->is_background_mode = command_is_background_mode;
    return 0;
}

char* command_get_command_name(command *self)
{
    return self->command_name;
}

char** command_get_arguments(command *self)
{
    return self->arguments;
}

int command_is_background_mode(command *self)
{
    return self->background;
}

int command_clean(command *self)
{
    free(self->command_name);
    free(self->arguments);
    return 0;
}