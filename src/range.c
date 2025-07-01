#include "include/range.h"
#include <stdlib.h>


ip_address_raw get_raw_ip(binary* b, u_int8_t pref) {
    ip_address_raw ip = {NULL, 0};
    if (b->len != 4 || pref > 32) {
        return ip;
    }
    ip.raw = (u_int8_t*) malloc(IP_V4_OCTETS * sizeof(u_int8_t));
    if (ip.raw == NULL) {
        return ip;
    }
    ip.pref = pref;
    for (int i = 0; i<IP_V4_OCTETS; i++) {
        ip.raw[i] = bin_to_u_i8(&b[i]);
    }
    return ip;
}