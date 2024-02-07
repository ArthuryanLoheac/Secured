/*
** EPITECH PROJECT, 2024
** ht_insert
** File description:
** ht_insert
*/

#include <unistd.h>
#include "secured.h"

static int parcours_entrys(hashtable_t *ht, char *key, char *value, int i)
{
    struct hash_line_s *entry = NULL;

    entry = ht->hash_table[i];
    while (entry != NULL) {
        if (entry->hash == ht->hash(key, ht->len)) {
            entry->path = value;
            return 0;
        }
        entry = entry->next;
    }
    return 1;
}

static int update_value(hashtable_t *ht, char *key, char *value)
{
    for (int i = 0; i < ht->len; i ++) {
        if (parcours_entrys(ht, key, value, i) == 0)
            return 0;
    }
    return -1;
}

struct hash_line_s *create_address(int hash,
    char *path, struct hash_line_s *next)
{
    struct hash_line_s *adresse = malloc(sizeof(struct hash_line_s));

    if (adresse == NULL) {
        return NULL;
        mini_printf("error creating the adress\n");
    }
    adresse->hash = hash;
    adresse->path = path;
    adresse->next = next;
    return adresse;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hashed = 0;
    int id = 0;

    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    if (ht_search(ht, key) != NULL)
        return update_value(ht, key, value);
    hashed = ht->hash(key, my_strlen(key));
    id = hashed % ht->len;
    if (ht->hash_table[id] == NULL)
        ht->hash_table[id] = create_address(hashed, value, NULL);
    else
        ht->hash_table[id] = create_address(hashed, value, ht->hash_table[id]);
    return 0;
}
