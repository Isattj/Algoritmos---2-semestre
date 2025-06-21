#include <stdio.h>

int main(){
    float nota1;
    float nota2;
    float nota3;
    float media;

    printf("Informe a nota 1:\n>");
    scanf("%f", &nota1);
    printf("Informe a nota 2:\n>");
    scanf("%f", &nota2);
    printf("Informe a nota 3:\n>");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3)/3;

    if (media > 8.5 && media <= 10.0){
       printf("Conceito A");
    } else if (media > 7.0 && media <= 8.5){
        printf("Conceito B");
    } else if (media > 5.5 && media <= 7.0){
        printf("Conceito c");
    }else if (media >= 0.0 && media <= 5.5){
        printf("Conceito D");
    }
    return 0;
}