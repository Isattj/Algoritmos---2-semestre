#include <stdio.h>

int main(){
    int a;
    int b;
    int mult;
    int divI;
    float divf;

    printf("Informe um numero inteiro: \n>");
    scanf("%d", &a);
    printf("Informe outro numero inteiro: \n>");
    scanf("%d", &b);

    mult = a * b;
    divI = a/b;
    divf = (float)a/b;

    printf("O valor da multiplicacao %d * %d = %d\n", a, b, mult);
    printf("O valor da divisao inteira %d / %d = %d\n", a, b, divI);
    printf("O valor da divisao float %.2f / %.2f = %.2f\n", (float)a, (float)b, divf);

    return 0;
}