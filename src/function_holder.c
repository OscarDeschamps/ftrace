/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** function_holder.c
*/

#include "ftrace_h.h"

int function_holder_allocate(fct_hold_t *hold)
{
    hold->size = 1000;
    hold->names = malloc(sizeof(char *) * (hold->size));
    if (!hold->names)
        return (1);
    hold->n = 0;
    return (0);
}

void function_holder_free(fct_hold_t *hold)
{
    for (size_t i = 0; i < hold->n; i++)
        free(hold->names[i]);
    free(hold->names);
}
