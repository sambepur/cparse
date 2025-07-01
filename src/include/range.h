#include <sys/types.h>
#include "binary.h"

#ifndef RANGE_H
#define RANGE_H

#define IP_V4_OCTETS 4
#define MAX_PREFIX_SIZE 32

typedef struct {
    u_int8_t* raw;
    int pref;
} ip_address_raw;

void print_raw_ip(ip_address_raw*);
ip_address_raw get_raw_ip(binary*, u_int8_t);

#endif