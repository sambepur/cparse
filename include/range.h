#include <sys/types.h>

#ifndef RANGE_H
#define RANGE_H

#ifdef __linux__
    #include "ansi.h"
#endif

typedef struct {
    int* bin;
    int len;
} binary;

typedef struct {
    u_int8_t* raw;
    int rng;
} ip_address;

u_int8_t bin_to_u_i8(binary);
binary to_unsigned_binary(u_int8_t);

#endif
