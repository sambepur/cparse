#include "include/ipr.h"

int main() {
    const char separ = '.';
    char* ip = "192.168.1.2.";
    node n = separate(ip, separ);
    if (n.tok == NULL) {
        printf("node malloc\n");
    }
    binary* b = (binary*) malloc(n.length * sizeof(binary));
    if (b == NULL) {
        printf("bin malloc\n");
    }
    for (int i = 0; i<n.length; i++) {
        b[i] = to_unsigned_binary(atoui8(n.tok[i].buff));
        if (b[i].bin == NULL) {
            printf("to un bin malloc\n");
        }
        printf("%b\n", bin_to_u_i8(b[i]));
    }
}