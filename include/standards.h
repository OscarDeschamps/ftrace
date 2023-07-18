/*
** EPITECH PROJECT, 2022
** FTRACE
** File description:
** standards.h
*/

#ifndef FTRACE_STANDARDS_H
    #define FTRACE_STANDARDS_H
    #include "list_func.h"
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/ptrace.h>
    #include <sys/user.h>
    #include <sys/wait.h>
    #include <sys/reg.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <sys/syscall.h>
    #include <stdbool.h>
    #include <sys/mman.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <elf.h>
    #include <sys/ptrace.h>
    #include <sys/user.h>
    #include <sys/wait.h>
    #include <sys/reg.h>
    #include <signal.h>
    typedef struct vs_s {
        char *file;
        int fd;
        struct stat sb;
        void *data;
    } vs_t;
#endif //FTRACE_STANDARDS_H
