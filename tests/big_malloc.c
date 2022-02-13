/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-leo.neumuller
** File description:
** simple_malloc
*/
#include "../include/my_malloc.h"
#include <assert.h>
#include <stdio.h>

int main()
{
    block_t b = sbrk(0);
    void *a = malloc(100000);
    void *c = sbrk(0);

    
    assert(b->size == 100000);
    assert(b->free == 0);
    assert(((long int)c - (long int)(void *)b) % (getpagesize() * 2) == 0);
    return 0;
}