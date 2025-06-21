#include <stdio.h>

int main(){
    int num;

    printf("Digite um numero inteiro:\n>");
    scanf("%d", &num);

    if (num % 2 == 0){
        printf("O numero %d e PAR", num);
    } else{
        printf("O numero %d e IMPAR", num);
    }
    return 0;
    
}