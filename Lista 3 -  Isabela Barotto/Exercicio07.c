#include <stdio.h>

int main(){
    int valor;
    int min=0;
    int max=0;
    printf("Digite um numero inteiro \n>");
    scanf("%d", &valor);

    while (valor != 0){
        if (valor > max){
            max = valor;
        }
        if (valor < min){
            min = valor;
        }
        printf("Digite um numero inteiro \n>");
        scanf("%d", &valor);
    }

    printf("Maior: %d \n", max);
    printf("Menor: %d \n", min);
    return 0;
}