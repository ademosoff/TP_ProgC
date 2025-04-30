#include <stdio.h>

int main() {
    unsigned int d = 0x10001000;

    unsigned int mask28 = 1 << 28;
    unsigned int mask12 = 1 << 12;

    if ((d & mask28) && (d & mask12)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
