#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define FREE(x) free(x); x=NULL; // idk why not
#define blocks(buffer, separator) (calc(buffer, separator).enc+1) // just help to calculate the blocks

typedef struct {
    int* offsets;
    size_t enc;
} meta;

typedef struct{
    char* buff;
    size_t length;
} token;

typedef struct {
    token* tok;
    size_t length;
} node;

int index(char*, char);
node separate(char*, char);
int cut(char*, char*, int, int);
size_t len(char*);
char* cpy(char*, char*, size_t);
meta calc(char*, char);

void dummy(){}           // debugging dummy
