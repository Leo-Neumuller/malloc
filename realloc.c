/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-leo.neumuller
** File description:
** realloc
*/
#include "./include/my_malloc.h"
// #include "utils.c"
#include "string.h"

void handle_insert_realloc(block_t current, void *ptr, size_t size)
{
    size_t available_size;

    available_size = (long int)(void *)current->next +
        current->next->size + BLOCKSIZE - (long int)ptr;
    if (current->next->next) {
        current->next = current->next->next;
    } else {
        current->next = NULL;
    }
    current->size = size;
    *current->nbfree -= 1;
    insert_block_if_possible(current, size);
}

block_t handle_new_block_realloc(block_t current, size_t size)
{
    block_t last;
    block_t oldcurrent =  current;

    while (current) {
        last = current;
        current = current->next;
    }
    current = handle_new_block(current, last, size);
    oldcurrent->free = 1;
    *oldcurrent->nbfree += 1;
    memcpy((void *)current + BLOCKSIZE,
    (void *)oldcurrent + BLOCKSIZE, oldcurrent->size);
    return current;
}

void *realloc(void *ptr, size_t size)
{
    block_t current = (void *)ptr - BLOCKSIZE;

    my_putstr("realloc\n");
    if (ptr == NULL) {
        my_putstr("ptr null\n");
        ptr = malloc(size);
        return ptr;
    }
    if (size <= 0) {
        free(ptr);
        return NULL;
    }
    if (size < current->size) {
        current->size = size;
        return ptr;
    }
    if (current->next && current->next->free
        && ((long int)(void *)current->next + current->next->size + BLOCKSIZE)
            - (long int)ptr >= size) {
                handle_insert_realloc(current, ptr, size);
    } else if (!current->next) {
        if (alloc_mem((void *)current, size) == NULL)
            return NULL;
        current->size = size;
    } else {
        current = handle_new_block_realloc(current, size);
    }
    return (void *)current + BLOCKSIZE;
}
