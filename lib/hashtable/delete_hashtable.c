/*
** EPITECH PROJECT, 2024
** delete_hashtable
** File description:
** delete_hashtable
*/
#include "secured.h"

void delete_hashtable(hashtable_t *ht)
{
    int len = 0;

    if (ht == NULL)
        return;
    len = ht->len;
    for (int i = 0; i < len; i++) {
        free(ht->hash_table[i]);
    }
    free(ht->hash_table);
    free(ht);
}
