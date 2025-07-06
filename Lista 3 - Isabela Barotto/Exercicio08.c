#include <stdio.h>

int main(){
    int a = 1;
    int b = 1;
    int n;
    int fib;
    int cont = 2;

    printf("Digite um numero inteiro \n>");
    scanf("%d", &n);


    while (cont != n){
        fib = a + b;
        a = b;
        b = fib;
        cont++;
    }

    printf("%d", fib);
    return 0;
}