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
    void *a = malloc(1000);
    block_t b = (void *)a - BLOCKSIZE;
    void *c = sbrk(0);
    void *u = malloc(1);

    free(a);
    a = malloc(100);
    my_assert((long int)b->next->size > 850 && (long int)b->next->size < 1000, "insert size ~ 900");
    my_assert(b->next->free == 1, "insert free 1");
    my_assert(b->size == 100, "size 100");
    my_assert(b->free == 0, "free 0");
    my_assert((long int)a % 8 == 0, "addr alligned");
    my_assert(((long int)b->next + BLOCKSIZE) % 8 == 0, "insert addr alligned");
    my_assert(((long int)c - (long int)(void *)l) % (getpagesize() * 2) == 0, "brk on pagesize");
    return 0;
}