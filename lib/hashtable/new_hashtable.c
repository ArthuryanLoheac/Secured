/*
** EPITECH PROJECT, 2024
** new_hashtable
** File description:
** new_hashtable
*/

#include "secured.h"

static struct hash_line_s **create_hash_line(int len)
{
    struct hash_line_s **adresse_book =
        malloc(sizeof(struct hash_line_s*) * len);

    if (adresse_book == NULL)
        return NULL;
    for (int i = 0; i < len; i++) {
        adresse_book[i] = NULL;
    }
    return adresse_book;
}

hashtable_t *new_hashtable(int(*hash)(char *, int), int len)
{
    hashtable_t *hashtable = malloc(sizeof(hashtable_t));

    if (hashtable == NULL || hash == NULL || len <= 0)
        return NULL;
    hashtable->hash = hash;
    hashtable->len = len;
    hashtable->hash_table = create_hash_line(len);
    return hashtable;
}
