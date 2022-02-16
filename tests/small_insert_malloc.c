/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-leo.neumuller
** File description:
** simple_malloc
*/
#include "../include/my_malloc.h"
#include "my_assert/my_assert.c"

int main()
{
    void *l = sbrk(0);
    void *a = malloc(100);
    block_t b = (void *)a - BLOCKSIZE;
    void *c = sbrk(0);
    void *u = malloc(9);

    free(a);
    a = malloc(63);
    my_assert((long int)b->next->size < 9, "insert size < 9");
    my_assert(b->next->free == 1, "insert free 1");
    my_assert(b->size == 63, "size 63");
    my_assert(b->free == 0, "free 0");
    my_assert((long int)a % 8 == 0, "addr alligned");
    my_assert(((long int)b->next + BLOCKSIZE) % 8 == 0, "insert addr alligned");
    my_assert(((long int)c - (long int)(void *)l) % (getpagesize() * 2) == 0, "brk on pagesize");
    return 0;
}