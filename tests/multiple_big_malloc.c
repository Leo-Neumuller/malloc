/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-leo.neumuller
** File description:
** simple_malloc
*/
#include "../include/my_malloc.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main()
{
    block_t b = sbrk(0);
    void *a[5000];
    void *c;
    char z;

    for (int i = 0; i < 5000; i++) {
        a[i] = malloc(100);
    }
    for (int i = 0; i < 5000; i++) {
        memset(a[i], 0, 100);
        for (int p = 0; p < 100; p++) {
            assert(((char *)a[i])[p] == 0);
        }
        free(a[i]);
    }
    c = sbrk(0);
    while (b != NULL) {
        assert(b->size == 100);
        assert(b->free == 1);
        assert(*b->nbfree == 5000);
        b = b->next;
    }
    assert(((long int)c - (long int)(void *)b) % (getpagesize() * 2) == 0);
    return 0;
}