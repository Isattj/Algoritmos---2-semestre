#include <stdio.h>

int main() {
    int linhas, i, j;
    scanf("%d", &linhas);

    for (i = 1; i <= linhas; i++) {
        for (j = 0; j < linhas - i; j++) {
            printf("  ");
        }
        for (j = 0; j < i; j++) {
            printf("[]");
        }
        printf("\n");
    }
    return 0;
}