/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-leo.neumuller
** File description:
** free
*/
#include "./include/my_malloc.h"
#include <assert.h>

void free(void *ptr)
{
    block_t info = ptr - BLOCKSIZE;

    my_putstr("free\n");

    if (ptr == NULL)
        return;
    if (info->free == 1)
        _exit(1);
    info->free = 1;
    *info->nbfree += 1;
}
