/*
** EPITECH PROJECT, 2022
** FTRACE
** File description:
** items_list_init.c
*/

#include "standards.h"

list_t *init_list(void)
{
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_item(list_t *list, char *name, unsigned long addr)
{
    item_t *new = malloc(sizeof(item_t));
    new->name = name;
    new->addr = addr;
    new->next = NULL;
    if (list->head == NULL) {
        list->head = new;
        list->tail = new;
    } else {
        list->tail->next = new;
        list->tail = new;
    }
}

void print_list(list_t *list)
{
    item_t *tmp = list->head;
    while (tmp) {
        printf("%s: %p\n", tmp->name, (void *)tmp->addr);
        tmp = tmp->next;
    }
}

void free_list(list_t *list)
{
    item_t *tmp = list->head;
    item_t *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    list->head = NULL;
    list->tail = NULL;
}
