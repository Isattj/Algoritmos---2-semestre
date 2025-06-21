#include <stdio.h>

int main(){
    int a;
    int b;
    int c;
    float media;
    float mediaP;

    printf("Digite o valor inteiro para A:\n>");
    scanf("%d", &a);
    printf("Digite o valor inteiro para B:\n>");
    scanf("%d", &b);
    printf("Digite o valor inteiro para C:\n>");
    scanf("%d", &c);

    media = ((float)a+b+c)/3;
    mediaP = ((10*(float)a)+(50*b)+(40*c))/100;

    printf("A media aritmetica dos valores %d, %d e %d e: %.2f\n", a, b, c, media);
    printf("A media ponderada dos valores %d, %d e %d e: %.2f\n", a, b, c, mediaP);
    return 0;
}