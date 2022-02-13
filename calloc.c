/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-leo.neumuller
** File description:
** calloc
*/
#include "./include/my_malloc.h"
#include <string.h>

void *calloc(size_t nmemb, size_t size)
{
    size_t total = nmemb * size;
    void *new = malloc(total);

    if (new == NULL)
        return NULL;
    memset(new, 0, total);
    return new;
}
