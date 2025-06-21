#include <stdio.h>

int main(){
    int a;
    int b;
    int c;

    printf("Digite um numero inteiro: \n>");
    scanf("%d", &a);
    printf("Digite um numero inteiro: \n>");
    scanf("%d", &b);
    printf("Digite um numero inteiro: \n>");
    scanf("%d", &c);

    if(a >= b){
        if (a>c){
            if (b > c){
                printf("%d > %d > %d", a, b, c); //a > b > c
            } else{
                printf("%d > %d > %d", a, c, b); //a > c > b
            }
        } else{
            printf("%d > %d > %d", c, a, b); //c > a > b     
        }
    } else if (b > a){
        if (b > c){
            if (a > b){
                printf("%d > %d > %d", a, b, c); //b > a > b     
            } else{
                printf("%d > %d > %d", b, c, a); //b > c > a     
            }
        } else{
            printf("%d > %d > %d", c, b, a); //c > b > a     
        }
    }
    return 0;
}