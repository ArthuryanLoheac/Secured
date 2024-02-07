/*
** EPITECH PROJECT, 2024
** secured.c
** File description:
** secured data storage solution using hashing
*/
#include "secured.h"
#include <stdio.h>

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 100);
    char str[5] = "!";

    for (int c = 33; c <= 'Z'; c ++) {
        ht_insert(ht, str, str);
        str[1] += 1;
        my_putstr(str);
        my_putstr(" : inserted\n");
    }
    ht_dump(ht);
    delete_hashtable(ht);
    return 0;
}