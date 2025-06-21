#include <stdio.h>

int main(){
    int a;
    int b;
    int c;
    int d;

    printf("Digite um numero inteiro: \n>");
    scanf("%d", &a);
    printf("Digite um numero inteiro: \n>");
    scanf("%d", &b);
    printf("Digite um numero inteiro: \n>");
    scanf("%d", &c);
    printf("Digite um numero inteiro: \n>");
    scanf("%d", &d);

    if(a>b && a>c && a>d){
        printf("O maior numero e %d", a);
    } else if (b>a && b>c && b>d){
        printf("O maior numero e %d", b);
    } else if (c>a && c>b && c>d){
        printf("O maior numero e %d", c);
    } else if (d>a && d>b && d>c){
        printf("O maior numero e %d", d);
    } else{
        printf("O maior numero e %d", a);
    }
    return 0;
}