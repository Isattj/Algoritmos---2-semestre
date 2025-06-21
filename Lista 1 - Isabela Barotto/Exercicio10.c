#include <stdio.h>

int main(){
    int numero;
    int mult;

    printf("Informe o numero: \n>");
    scanf("%d", &numero);

    mult = numero * 1;
    printf("%2d X 1 = %2d\n", numero, mult);

    mult = numero * 2;
    printf("%2d X 2 = %2d\n", numero, mult);

    mult = numero * 3;
    printf("%2d X 3 = %2d\n", numero, mult);

    mult = numero * 4;
    printf("%2d X 4 = %2d\n", numero, mult);

    mult = numero * 5;
    printf("%2d X 5 = %2d\n", numero, mult);

    mult = numero * 6;
    printf("%2d X 6 = %2d\n", numero, mult);

    mult = numero * 7;
    printf("%2d X 7 = %2d\n", numero, mult);

    mult = numero * 8;
    printf("%2d X 8 = %2d\n", numero, mult);

    mult = numero * 9;
    printf("%2d X 9 = %2d\n", numero, mult);

    mult = numero * 10;
    printf("%2d X 10 = %2d\n", numero, mult);
    return 0;
}