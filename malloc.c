/*
** EPITECH PROJECT, 2022
** bs-malloc
** File description:
** strc
*/
#include "./include/my_malloc.h"

static void *handle_begining(void **beginning, size_t size, block_t *last)
{
    block_t current;
    static int nbfree = 0;
    int offset_allign;

    *beginning = alloc_mem(NULL, size);
    if (*beginning == NULL)
        return NULL;
    offset_allign = get_offset_allign(*beginning);
    *beginning += offset_allign;
    set_block_metadata((block_t)*beginning, size, 0);
    current = *beginning;
    current->nbfree = &nbfree;
    *last = current;
    return (void *)current + BLOCKSIZE;
}

void *malloc(size_t size)
{
    static void *beginning = NULL;
    block_t current;
    static block_t last = NULL;

    if (beginning == NULL) {
        return handle_begining(&beginning, size, &last);
    } else {
        current = find_free_block(&last, beginning, size);
        current = handle_free_or_new(current, last, size);
        if (current == NULL)
            return NULL;
        last = current;
        return (void *)current + BLOCKSIZE;
    }
    return NULL;
}
