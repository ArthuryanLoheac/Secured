/*
** EPITECH PROJECT, 2024
** ht_dump
** File description:
** ht_dump
*/
#include "secured.h"

void ht_dump(hashtable_t *ht)
{
    int len = 0;
    struct hash_line_s *j = NULL;

    if (ht == NULL)
        return;
    len = ht->len;
    for (int i = 0; i < len; i++) {
        mini_printf("[%d]:\n", i);
        j = ht->hash_table[i];
        while (j != NULL) {
            mini_printf("> %d - %s\n", j->hash, j->path);
            j = j->next;
        }
    }
}
