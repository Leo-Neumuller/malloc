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

    assert(info->free == 0);
    info->free = 1;
    *info->nbfree += 1;
}
