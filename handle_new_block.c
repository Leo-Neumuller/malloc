/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-leo.neumuller
** File description:
** handle_free_insert
*/
#include "./include/my_malloc.h"

block_t find_free_block(block_t *last, void *beginning, size_t size)
{
    block_t current = (block_t)beginning;

    if (*current->nbfree == 0) {
        return NULL;
    }
    while (current != NULL && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }

    return current;
}

int get_offset_allign(void *tmp)
{
    int offset_alling = 0;

    if (((long int)tmp + BLOCKSIZE) % 8 != 0) {
        offset_alling = 8 - (((long int)tmp + BLOCKSIZE) % 8);
    }
    return offset_alling;
}

block_t handle_new_block(block_t current, block_t last, size_t size)
{
    int offset_allign = 0;
    void *tmp;

    current = (void *)last + last->size + BLOCKSIZE;
    offset_allign = get_offset_allign((void *)current);
    tmp = (void *)current;
    tmp += offset_allign;
    current = tmp;
    if (alloc_mem((void *)current, size + offset_allign) == NULL)
        return NULL;
    last->next = (void *)current;
    current->nbfree = last->nbfree;
    set_block_metadata(current, size, 0);
    return current;
}

void insert_block_if_possible(block_t current, block_t last, size_t size)
{
    block_t new;
    int offset_allign = 0;
    size_t newsize = 0;
    void *tmp;

    (void)last;
    if ((void *)current + (BLOCKSIZE * 2) + size + 8 < (void *)current->next) {
        new = (void *)current + BLOCKSIZE + size;
        offset_allign = get_offset_allign((void *)new);
        tmp = (void *)new;
        tmp += offset_allign;
        new = tmp;
        newsize = (void *)current->next - ((void *)new + BLOCKSIZE);
        set_block_metadata(new, newsize, 0);
        new->free = 1;
        new->nbfree = current->nbfree;
        *new->nbfree += 1;
        new->next = current->next;
        current->next = new;
    }
}

block_t handle_free_or_new(block_t current, block_t last, size_t size)
{
    if (current != NULL) {
        set_block_metadata(current, size, 1);
        insert_block_if_possible(current, last, size);
        *current->nbfree -= 1;
    } else {
        current = handle_new_block(current, last, size);
    }
    return current;
}
