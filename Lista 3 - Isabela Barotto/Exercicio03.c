#include <stdio.h>

int main(){
    int  n;
    int quadrado = 0;
    int cont = 0;
    int valor = 1;
    printf("Digite um numero inteiro \n>");
    scanf("%d", &n);

    while (cont != n){
        quadrado = quadrado + valor;
        printf("%d", valor);
        valor = valor + 2;
        cont++;
        if (cont != n){
            printf(" + ");
        }
    }

    printf(" = %d", quadrado);
    return 0;
}