#include <stdio.h>

int main() {
    int i;
    for (i = 33; i <= 125; i++) {
        printf("%03d %03X %c", i, i, i);
        if ((i - 32) % 3 == 0) printf("\n");
        else printf(" ");
    }
    return 0;
}