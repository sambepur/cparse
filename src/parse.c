#include "include/parse.h"

int is_digit(char w) {
    return (w >= '0' && w <= '9');
}

char* cpy(char* buff_1, char* buff_2, size_t l) {
    while(l--) {
        *buff_2++ = *buff_1++; 
    }
    if (!buff_2)
    return NULL;
    else
    return buff_2;
}

size_t len(char* buff) {
    size_t t = 0;
    for (char* c = buff; *c!=0; c++) {
        t++;
    }
    return t;
}
int cut(char* buff, char* res, int start, int offset) {
    if (start > offset){
        return -1;
    }
    for (int i = 0; i<(offset-start); i++) {
        res[i] = buff[start+i];
    }
    res[offset] = 0;
    return 0;
}

node separate(char* buffer, char w) {
    int r, x = 0;
    meta m = calc(buffer, w);
    node n = {
        (token*) malloc(m.enc * sizeof(token)),
        m.enc
    };
    for (int i = 0; i<m.enc; i++) {
        n.tok[i].length = m.offsets[i]-x;
        n.tok[i].buff = (char*) malloc(n.tok[i].length);
        if (n.tok->buff != NULL) {
            r = cut(buffer, n.tok[i].buff, x, m.offsets[i]);
            x = m.offsets[i]+1;
        }
        else {
            FREE(n.tok);
            n.length = 0;
            FREE(m.offsets);
            return n;
        }
    }
    FREE(m.offsets);
    return n;
}

// calculate encounters of character in buffer and their positions 
meta calc(char* buff, char w) {
    meta m = {NULL, 0};
    size_t l = len(buff);
    for (int i = 0; i<l; i++) {
        if (buff[i] == w) {
            m.enc++;
        }
    }
    if (m.enc > 0) {
        m.offsets = (int*) malloc(m.enc * sizeof(int));
        if (!m.offsets) {
            m.enc = 0;
            m.offsets = NULL;
            return m;
        }
        else {
            int inc = 0;
            for (int i = 0; i<l; i++) {
                if (buff[i] == w) {
                    m.offsets[inc++] = i;
                }
            }
        }
    }
    return m;
}

u_int8_t atoui8(char *str) {
    u_int8_t value = 0;
    if (*str == '\0') {
        return 0;
    }

    while (*str != '\0') {
        if (!is_digit(*str)) {
            return 0;
        }

        value = value * 10 + (*str - '0');

        if (value > 255) {
            return 0; 
        }

        str++;
    }
    return value;
}