#include <stdio.h>

int main(){
    float grau;
    const float PI = 3.141593;
    float rad;

    printf("Digite o valor em graus: \n>");
    scanf("%f", &grau);

    rad = (grau * PI)/180;

    printf("O grau: %.2f em radianos e: %.2f\n", grau, rad);
    return 0;
}