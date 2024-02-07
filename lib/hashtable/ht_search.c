/*
** EPITECH PROJECT, 2024
** ht_search
** File description:
** ht_search : find data given a key in a hashtable, returns NULL if error
*/

#include "secured.h"
#include "unistd.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int adress = 0;
    struct hash_line_s *line = NULL;

    if (ht == NULL || key == NULL)
        return NULL;
    adress = ht->hash(key, ht->len);
    line = ht->hash_table[adress % ht->len];
    while (line != NULL) {
        if (adress == line->hash) {
            return line->path;
        }
        line = line->next;
    }
    return NULL;
}
