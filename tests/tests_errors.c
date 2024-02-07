/*
** EPITECH PROJECT, 2024
** tests.c
** File description:
** criterion tests
*/
#include "secured.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>


Test(hash, key_NULL)
{
    cr_assert(hash(NULL, 8) == -1);
}

Test(hash, len_neg)
{
    cr_assert(hash("NULL", -1) == -1);
}

Test(ht_search, ht_NULL)
{
    cr_assert(ht_search(NULL, "QUOI") == NULL);
}

Test(ht_search, key_null)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    cr_assert(ht_search(ht, NULL) == NULL);
}

Test(new_hashtable, hash_null)
{
    cr_assert(new_hashtable(NULL, 4) == NULL);
}

Test(new_hashtable, len_neg)
{
    cr_assert(new_hashtable(&hash, -5) == NULL);
}

Test(ht_insert, ht_insert_null)
{
    cr_assert(ht_insert(NULL, "QUOI", "FEUR") == -1);
}

Test(ht_insert, wrong_key)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    cr_assert(ht_insert(ht, NULL, "FEUR") == -1);
}

Test(ht_insert, wrong_value)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    cr_assert(ht_insert(ht, "QUOI", NULL) == -1);
}

Test(ht_delete, delete_non_existing_entry)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_delete(ht, "banana");
    ht_insert(ht, "banana", "yummi");
    ht_delete(ht, "minions");
}

Test(ht_delete, ht_is_null)
{
    hashtable_t *ht = NULL;

    ht_delete(ht, "banana");
}
