/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-leo.neumuller
** File description:
** alloc_memory
*/
#include "./include/my_malloc.h"

void *alloc_mem(void *current, size_t size)
{
    if (current == NULL)
        current = sbrk(0);
    while ((void *)current + size + BLOCKSIZE > sbrk(0)) {
        if (sbrk(getpagesize() * 32) == (void *)-1)
            return NULL;        
    }
    return current;
}

void set_block_metadata(block_t current, size_t size, char hasnext)
{
    current->size = size;
    if (!hasnext)
        current->next = NULL;
    current->free = 0;
}
