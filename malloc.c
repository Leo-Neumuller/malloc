/*
** EPITECH PROJECT, 2022
** bs-malloc
** File description:
** strc
*/
#include <stdio.h>
#include <unistd.h>
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

block_t find_free_block(block_t *last, void *beginning, size_t size)
{
    block_t current = (block_t)beginning;

    while (current != NULL && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }

    return current;
}

block_t handle_free_or_new(block_t current, block_t last, size_t size)
{
    if (current != NULL) {
        set_block_metadata(current, size, 1);
    } else {
        if (alloc_mem((void *)last + last->size + BLOCKSIZE, size) == NULL)
            return NULL;
        current = (void *)last + last->size + BLOCKSIZE;
        last->next = (void *)current;
        set_block_metadata(current, size, 0);
    }
    return current;
}

void *malloc(size_t size)
{
    static void *beginning = NULL;
    block_t current;
    block_t last = NULL;

    if (beginning == NULL) {
        beginning = alloc_mem(NULL, size);
        set_block_metadata((block_t)beginning, size, 0);
        return beginning + BLOCKSIZE;
    } else {
        current = find_free_block(&last, beginning, size);
        current = handle_free_or_new(current, last, size);
        return (void *)current + BLOCKSIZE;
    }
    return NULL;
}
