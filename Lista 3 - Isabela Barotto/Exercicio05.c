#include <stdio.h>

int main(){
    int  a;
    int  b;
    int div = 0;
    int resto = 0;
    int sinal = 1;

    printf("Digite um numero inteiro \n>");
    scanf("%d", &a);

    printf("Digite um numero inteiro \n>");
    scanf("%d", &b);

    if (a < 0){
        a = -a;
        sinal *= -1;
    }
    if (b<0){
        b = -b;
        sinal *= -1;
    }

    printf("%d \n", a);
    resto = a;
    while(resto >= b){
        resto = resto - b;
    }

    div = (a - resto)/b;
    div *= sinal;
    
    printf(" %d / %d = %d \n", a, b, div);
    printf("%d  %d  = %d", a, b, resto);
    return 0;
}