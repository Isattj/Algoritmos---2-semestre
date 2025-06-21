#include <stdio.h>

int main(){
    int a;
    int b;
    int resto;
    int resto2;
    float div;

    printf("Informe um numero inteiro para A: \n>");
    scanf("%d", &a);
    printf("Informe um numero inteiro para B: \n>");
    scanf("%d", &b);

    resto = a % b;

    div = a/b;
    resto2 = a - (b * div);

    printf("1- O resto da divisão: %d / %d = %d\n", a, b, resto);
    printf("2- O resto da divisão: %d / %d = %d\n", a, b, resto2);
    return 0;
}