/*
** EPITECH PROJECT, 2024
** tests.c
** File description:
** criterion tests
*/
#include "secured.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(new_hashtable, invalid_inputs)
{
    hashtable_t *ht = new_hashtable(NULL, -56789);
    hashtable_t *ht2 = new_hashtable(NULL, 0);

    ht = ht2;
    ht2 = ht;
}

Test(delete_hashtable, empty_filled_null)
{
    hashtable_t *ht_empty = new_hashtable(&hash, 10);
    hashtable_t *ht_filled = new_hashtable(&hash, 4);
    hashtable_t *ht_null = new_hashtable(NULL, -10);

    ht_insert(ht_filled, "1", "yo");
    ht_insert(ht_filled, "2", "you");
    ht_insert(ht_filled, "3", "youp");
    ht_insert(ht_filled, "4", "youpi");
    ht_insert(ht_filled, "re!:tr nblrgdezunhjtrpieh'(zoly)", "ooooooooooooooooooooooooooooooooooooooooo");
    delete_hashtable(ht_empty);
    delete_hashtable(ht_filled);
    delete_hashtable(ht_null);
}

Test(ht_search, existing_entry)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "Chickens", "I love them !!!");
    ht_insert(ht, "Cows", "Not that cool ...");
    ht_insert(ht, "Pigs", "Smells bad :(");
    cr_assert_str_eq(ht_search(ht, "Pigs"), "Smells bad :(");
    cr_assert_str_eq(ht_search(ht, "Cows"), "Not that cool ...");
    cr_assert_str_eq(ht_search(ht, "Chickens"), "I love them !!!");
}

Test(ht_search, empty_table, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_search(ht, "Pigs");
    ht_search(ht, "Cows");
    ht_search(ht, "Chickens");
}

Test(ht_dump, empty_table, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_dump(ht);
    cr_assert_stdout_eq_str("[0]:\n[1]:\n[2]:\n[3]:\n[4]:\n[5]:\n[6]:\n[7]:\n[8]:\n[9]:\n");
}

Test(ht_insert, update_entry, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    ht_insert(ht, "banana", "yummi");
    ht_insert(ht, "banana", "love bananas");
    ht_insert(ht, "orange", "wow");
    ht_insert(ht, "orange", "no !");
    ht_delete(ht, "banana");
    ht_delete(ht, "orange");
    ht_dump(ht);
    cr_assert_stdout_eq_str("[0]:\n[1]:\n[2]:\n");
}

Test(ht_delete, delete_3_elements, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 10);

    ht_insert(ht, "banana", "yummi");
    ht_insert(ht, "minions", "love bananas");
    ht_insert(ht, "gru", "love minions");
    ht_delete(ht, "banana");
    ht_delete(ht, "minions");
    ht_delete(ht, "gru");
    ht_dump(ht);
    cr_assert_stdout_eq_str("[0]:\n[1]:\n[2]:\n[3]:\n[4]:\n[5]:\n[6]:\n[7]:\n[8]:\n[9]:\n");
}

Test(ht_delete, lots_of_elements, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "a", "yummi");
    ht_insert(ht, "b", "love bananas");
    ht_insert(ht, "c", "love minions");
    ht_insert(ht, "d", "yo");
    ht_insert(ht, "e", "foo");
    ht_insert(ht, "f", "faa");
    ht_insert(ht, "g", "fii");
    ht_insert(ht, "h", "suuu");
    ht_insert(ht, "i", "jiiii");
    ht_delete(ht, "a");
    ht_delete(ht, "b");
    ht_delete(ht, "c");
    ht_delete(ht, "d");
    ht_delete(ht, "e");
    ht_delete(ht, "f");
    ht_delete(ht, "g");
    ht_delete(ht, "h");
    ht_delete(ht, "i");
    ht_dump(ht);
    cr_assert_stdout_eq_str("[0]:\n[1]:\n[2]:\n[3]:\n[4]:\n");
}
