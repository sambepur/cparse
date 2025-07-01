#include <sys/types.h>
#include <stdlib.h>
#include <stddef.h>
#ifndef BINARY_H
#define BINARY_H

typedef struct {
    int* bin;
    int len;
} binary;

u_int8_t bin_to_u_i8(binary*);
binary to_unsigned_binary(u_int8_t);

#endif