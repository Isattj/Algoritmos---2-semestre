#include <stdio.h>

int main(){
    int a;
    int b;
    int soma;
    int sub;

    printf("Informe um numero inteiro:\n>");
    scanf("%d", &a);

    printf("Informe outro numero inteiro:\n>");
    scanf("%d", &b);

    soma = a + b;
    sub = a - b;

    printf("O resultado da soma: %d + %d = %d \n", a, b, soma);
    printf("O resultado da subtracao: %d - %d = %d\n", a, b, sub);
    return 0;
}