#include <stdio.h>

int main() {
    int h, w, i, j;
    scanf("%d %d", &h, &w);

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("[]");
        }
        printf("\n");
    }
    return 0;
}