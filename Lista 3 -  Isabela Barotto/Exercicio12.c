#include <stdio.h>

int main(){
    int  num;
    int i = 1;
    int cont = 0;

    printf("Digite um numero inteiro \n>");
    scanf("%d", &num);

    while (i <= num){
        if (num%i == 0){
            cont++;
        }
        i++;
    }

    if (cont == 2){
        printf("Primo");
    } else {
        printf("Nao e primo");
    }
    return 0;
}