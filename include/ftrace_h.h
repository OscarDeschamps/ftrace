/*
** EPITECH PROJECT, 2022
** FTRACE
** File description:
** ftrace_h.h
*/

#ifndef FTRACE_H
    #define FTRACE_H
    #include <unistd.h>
    #include "list_func.h"
    list_t *get_items(int argc, char *argv[]);
    typedef struct fct_hold_s {
        char **names;
        size_t size;
        size_t n;
    } fct_hold_t;
    typedef struct ftrace_h
    {
        char *prog_name;
        pid_t child;
        size_t f_index;
        fct_hold_t fct_hold;
    } ftrace_t;
    int function_holder_allocate(fct_hold_t *hold);
    void function_holder_free(fct_hold_t *hold);
#endif //FTRACE_H
