/*
** EPITECH PROJECT, 2024
** secured.h
** File description:
** main header file for the secured project
*/

#ifndef SECURED_H_
    #define SECURED_H_

    #include "secured.h"
    #include <stddef.h>
    #include <stdlib.h>

struct hash_line_s {
    int hash;
    char *path;
    struct hash_line_s *next;
};

typedef struct hashtable_s {
    struct hash_line_s **hash_table;
    int len;
    int (*hash)(char *, int);
} hashtable_t;

int my_strlen(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int mini_printf(const char *format, ...);
int my_compute_power_rec(int nb, int p);

int hash(char *key, int len);
hashtable_t *new_hashtable(int(*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

#endif /* !SECURED_H_ */
