#include "include/range.h"
#include <stdlib.h>



u_int8_t bin_to_u_i8(binary b) {
    u_int8_t bin = 0b0;
    for (int i = 0; i < b.len; i++) {
        if (i == b.len -1) {
            bin |= b.bin[i];
            return bin;
        }
        bin = (bin | b.bin[i]) << 1;
    }
    return bin;
}

binary to_unsigned_binary(u_int8_t n) {
    binary b = {NULL, 0};
    int c = 0;
    int x = n;
    int* vals = NULL;
    int* rev = NULL;
    while (x > 0) {
        c++;
        x/=2;
    }
    vals = (int*) malloc(sizeof(int) * c);
    if (vals != NULL) {
        for (int i = 0; i<c; i++) {
            vals[i] = n%2;
            n/=2;
        }
    }
    else {
        return b;
    }
    int cr = c;
    rev = (int*) malloc(sizeof(int) * c);
    if (rev == NULL) {
        free(vals);
        vals = NULL;
        return b;
    }
    for (int i = 0; i<c; i++) {
        rev[i] = vals[c - i -1];
    }
    free(vals);
    vals = NULL;
    b.bin = rev;
    b.len = c;
    return b;
}