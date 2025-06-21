#include <stdio.h>

int main(){
    int valor;
    int soma = 0;
    float media;
    int cont = 0;
    while (valor != 0){
        printf("Digite um numero inteiro \n>");
        scanf("%d", &valor);
        soma += valor;
        cont++;
    }

    media = (float)soma / cont;
    printf("Soma: %d \n", soma);
    printf("Media: %.2f \n", media);
    return 0;
}