/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-strace-oscar.deschamps
** File description:
** strace
*/

#include "../include/strace.h"

int print_args(struct user_regs_struct regs, int i)
{
    unsigned long long regi[] = {regs.rdi, regs.rsi, regs.rdx,
    regs.r10, regs.r9, regs.r8};
    int count = 0;

    for (int y = 0; y != table[i].nargs; y++) {
        count += printf("0x%llx", regi[y]);
        if (y + 1 != table[i].nargs) {
            printf(", ");
            count += 2;
        }
    }
    printf(") ");
    return (count + 2);
}

void strace_bis(pid_t child, list_t *list)
{
    struct user_regs_struct regs;
    item_t *item = list->head;

    ptrace(PT_GETREGS, child, NULL, &regs);
    if (print_syscall(child) == 84) {
        while (item != NULL) {
            IF_DO(regs.rip == item->addr,
            printf("Entering Function %s at %lx\n",
            item->name, item->addr);
            break;
            )
            item = item->next;
        }
    }
}