/*
** EPITECH PROJECT, 2024
** hash.c
** File description:
** contains the hash function of the secured project
*/
#include "secured.h"

int hash(char *key, int len)
{
    double value = 0;

    if (key == NULL || len <= 0)
        return 0;
    for (int i = 0; i < my_strlen(key); i++) {
        value += (key[i] * my_compute_power_rec(10, i));
    }
    for (int i = 0; i < 5; i ++) {
        value = my_compute_power_rec(value, 3);
        value = value / 3.14159265358979323;
        value = (value - ((int)(value)))*345678967;
        if (value < 0)
            value = -value;
    }
    return (int)(value);
}
