#include <stdio.h>

int main(){
    float r;
    float diametro;
    float circun;
    float area;
    const float PI = 3.141593;

    printf("Informe o raio do circulo:\n>");
    scanf("%f", &r);

    diametro = 2 * r;
    circun = 2 * PI * r;
    area = (r*r) * PI;

    printf("O circulo de raio %.2f possui:\n", r);
    printf("Diametro: %.2f\n", diametro);
    printf("Circunferencia: %.2f\n", circun);
    printf("Area: %.2f\n", area);
    return 0;
}