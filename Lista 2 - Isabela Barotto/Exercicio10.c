#include <stdio.h>

int main(){
    char letra;
    printf("Digite uma letra:\n>");
    scanf("%c", &letra);

    if((letra >= 'a' && letra<='z')){
        letra = letra - 32;
        printf("Letra em maiusculo: %c", letra);
    } else if((letra >= 'A' && letra<='Z')){
        printf("Letra em maiusculo: %c", letra);
    } else{
        printf("O caracter digitado nao e uma letra!");
    }
    return 0;
}