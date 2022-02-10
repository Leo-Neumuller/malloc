/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-leo.neumuller
** File description:
** free
*/
#include "./include/my_malloc.h"

void free(void *ptr)
{
    block_t info = ptr - BLOCKSIZE;

    info->free = 1;
}
