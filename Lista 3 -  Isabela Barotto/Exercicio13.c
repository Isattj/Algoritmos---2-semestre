#include <stdio.h>

int main(){
    int  num;
    int fator = 2;
    int cont = 0;

    printf("Digite um numero inteiro \n>");
    scanf("%d", &num);


    while (num > 1){
        cont = 0;
        while (num % fator == 0){
            num = num / fator;
            cont++;
        }

        if (cont > 0){
            printf("%d x fator %d \n", cont, fator);
        }

        fator++;
    }

    return 0;
}