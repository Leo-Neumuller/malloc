/*
** EPITECH PROJECT, 2022
** bs-malloc
** File description:
** strc
*/

#ifndef STRC_H_
#define STRC_H_
#include <stdio.h>

void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);

typedef struct block_s *block_t;
struct block_s {
    size_t size;
    block_t next;
    int free;
};

#define BLOCKSIZE 20

#endif /* !STRC_H_ */
