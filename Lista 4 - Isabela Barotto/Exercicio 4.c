#include <stdio.h>

int main() {
    int num, i, soma = 0;
    scanf("%d", &num);

    printf("Divisores de %d: ", num);
    for (i = 1; i < num; i++) {
        if (num % i == 0) {
            soma += i;
            printf("%d", i);
            if (soma < num) printf(" + ");
        }
    }

    printf(" = %d\n", soma);
    if (soma == num) printf("Numero perfeito? Sim\n");
    else printf("Numero perfeito? Nao\n");

    return 0;
}