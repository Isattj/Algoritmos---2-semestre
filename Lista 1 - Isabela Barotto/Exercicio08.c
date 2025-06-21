#include <stdio.h>

int main(){
    int a;
    int b;
    int c;
    float pesoA;
    float pesoB;
    float pesoC;
    float mediaP;

    printf("Digite o valor inteiro para A:\n>");
    scanf("%d", &a);
    printf("Digite o peso para o numero A:\n>");
    scanf("%d", &pesoA);

    printf("Digite o valor inteiro para B:\n>");
    scanf("%d", &b);
    printf("Digite o peso para o numero B:\n>");
    scanf("%d", &pesoB);

    printf("Digite o valor inteiro para C:\n>");
    scanf("%d", &c);
    printf("Digite o peso para o numero B:\n>");
    scanf("%d", &pesoC);

    mediaP = ((pesoA*(float)a)+(pesoB*b)+(pesoC*c))/(pesoA+pesoB+pesoC);

    printf("A media ponderada dos valores %d, %d e %d e: %.2f\n", a, b, c, mediaP);
    return 0;
}