#include <stdio.h>

int main(){
    int  a;
    int  b;
    int cont = 0;
    int mult = 0;

    printf("Digite um numero inteiro \n>");
    scanf("%d", &a);

    printf("Digite um numero inteiro \n>");
    scanf("%d", &b);

    while (cont != b){
        mult = mult + a;
        cont++;
    }

    printf(" %d x %d = %d", a, b, mult);
    return 0;
}