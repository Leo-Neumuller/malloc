/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-leo.neumuller
** File description:
** reallocarray
*/
#include "./include/my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    my_putstr("reallocarray\n");
    return realloc(ptr, nmemb * size);
}
