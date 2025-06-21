#include <stdio.h>

int main(){
    float l;
    float a;
    float perimetro;
    float area;

    printf("Informe a largura do retangulo:\n>");
    scanf("%f", &l);

    printf("Informe a altura do retangulo:\n>");
    scanf("%f", &a);

    perimetro = (a*2)+(l*2);
    area = l * a;

    printf("O retangulo de altura %.2f e largura %.2f tem perimetro: %.2f e area: %.2f\n", a, l, perimetro, area);

    return 0;
}