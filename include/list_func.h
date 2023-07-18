/*
** EPITECH PROJECT, 2022
** FTRACE
** File description:
** list_func.h
*/

#ifndef FTRACE_LIST_FUNC_H
    #define FTRACE_LIST_FUNC_H
    typedef struct item_s {
        char *name;
        unsigned long addr;
        struct item_s *next;
    } item_t;
    typedef struct list_s {
        item_t *head;
        item_t *tail;
    } list_t;
    typedef struct sym_data_s {
        char *symtab;
        int symtab_size;
        int symtab_entry_size;
        char *symstrtab;
    } sd_t;
    list_t *init_list(void);
    void add_item(list_t *list, char *name, unsigned long addr);
    void print_list(list_t *list);
    void free_list(list_t *list);
#endif //FTRACE_LIST_FUNC_H
