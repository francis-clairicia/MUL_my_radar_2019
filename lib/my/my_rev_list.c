/*
** EPITECH PROJECT, 2019
** my_rev_list
** File description:
** Reverse a linked list
*/

#include <mylist.h>

void my_rev_list(list_t **begin)
{
    list_t *new_list = NULL;
    list_t *node = *begin;

    while (node != NULL) {
        my_put_in_list(&new_list, node->data);
        node = node->next;
    }
    my_free_list(begin, 0);
    *begin = new_list;
}
