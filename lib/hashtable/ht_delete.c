/*
** EPITECH PROJECT, 2024
** ht_delete
** File description:
** ht_delete
*/
#include "secured.h"
#include <unistd.h>

int free_and_return(struct hash_line_s *actual)
{
    free(actual);
    return 1;
}

int delete_adress(struct hash_line_s **hash_line,
    struct hash_line_s *to_delete)
{
    struct hash_line_s *actual = NULL;
    struct hash_line_s *last = NULL;

    if (hash_line == NULL || to_delete == NULL)
        return 0;
    actual = *hash_line;
    while (actual != NULL) {
        if (actual->hash == to_delete->hash && last != NULL) {
            last->next = actual->next;
            return free_and_return(actual);
        }
        if (actual->hash == to_delete->hash && last == NULL) {
            *hash_line = NULL;
            return free_and_return(actual);
        }
        last = actual;
        actual = actual->next;
    }
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int adress = 0;
    struct hash_line_s *line = NULL;
    int founded = 0;

    if (ht == NULL || key == NULL)
        return 84;
    adress = ht->hash(key, ht->len);
    line = ht->hash_table[adress % ht->len];
    while (line != NULL) {
        if (adress == line->hash)
            founded += delete_adress(&ht->hash_table[adress % ht->len], line);
        line = line->next;
    }
    if (founded == 0) {
        write(2, "Entry not found\n", 17);
        return 84;
    }
    return 0;
}
