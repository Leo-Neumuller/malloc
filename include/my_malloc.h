/*
** EPITECH PROJECT, 2022
** bs-malloc
** File description:
** strc
*/

#ifndef STRC_H_
#define STRC_H_
#include <stdio.h>
#include <unistd.h>

typedef struct block_s *block_t;
struct block_s {
    size_t size;
    block_t next;
    int *nbfree;
    int free;
};

#define BLOCKSIZE 28

void set_block_metadata(block_t current, size_t size, char hasnext);
block_t find_free_block(block_t *last, void *beginning, size_t size);
block_t handle_free_or_new(block_t current, block_t last, size_t size);
void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *alloc_mem(void *current, size_t size);
void *calloc(size_t nmemb, size_t size);

#endif /* !STRC_H_ */
