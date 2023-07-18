/*
** EPITECH PROJECT, 2022
** FTRACE
** File description:
** ptrace_h.h
*/

#ifndef FTRACE_PTRACE_H
    #define FTRACE_PTRACE_H
    #include "ftrace_h.h"
    #include "standards.h"
    #include <sys/ptrace.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/user.h>
    #include <sys/reg.h>
    #include <sys/syscall.h>
    #include <sys/mman.h>
    #include <sys/stat.h>
    #include <sys/uio.h>
    #include <sys/utsname.h>
    #include <sys/time.h>
    #include <sys/resource.h>
    void main_tracer(list_t *items, char *argv[]);
#endif //FTRACE_PTRACE_H
