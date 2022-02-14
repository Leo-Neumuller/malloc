/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-leo.neumuller
** File description:
** simple_malloc
*/
#include "../include/my_malloc.h"
#include <stdio.h>
#include <string.h>
#include "my_assert/my_assert.c"

int main()
{
    void *l = sbrk(0);
    void *a[5000];
    block_t b;
    void *c;
    char z;

    for (int i = 0; i < 5000; i++) {
        a[i] = calloc(100, 1);
    }
    b = (void *)a[0] - BLOCKSIZE;
    for (int i = 0; i < 5000; i++) {
        for (int p = 0; p < 100; p++) {
            my_assert(((char *)a[i])[p] == 0, "mem not set to 0");
        }
        my_assert((long int)a[i] % 8 == 0, "addr alligned");
        free(a[i]);
    }
    c = sbrk(0);
    while (b != NULL) {
        my_assert(b->size == 100, "size 100");
        my_assert(b->free == 1, "free 1");
        my_assert(*b->nbfree == 5000, "free 5000");
        b = b->next;
    }
    my_assert(((long int)c - (long int)(void *)l) % (getpagesize() * 2) == 0, "brk on pagesize");
    return 0;
}