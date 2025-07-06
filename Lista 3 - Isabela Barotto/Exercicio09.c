#include <stdio.h>

int main(){
    int  x;
    int  d;
    int cont = 0;
    int mult = 0;

    printf("Digite um numero inteiro \n>");
    scanf("%d", &x);

    while (x != 0){
        d = x % 10;
        printf(" %d\n", d);
        x = x / 10;
    }

    
    return 0;
}